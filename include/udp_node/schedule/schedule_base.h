#pragma once

#include <queue>
#include <memory>
#include <cstdint>

#include <mutex>
#include <condition_variable>
#include <thread>

namespace KAI
{
    namespace Schedule
    {
        class LetterBase
        {
        public:
            virtual uint16_t SetMessage(uint8_t *buf) = 0;
        };

        using Letter_ptr = std::shared_ptr<LetterBase>;

        template <typename T>
        class Task_CRTP : public LetterBase
        {
        public:
            uint16_t SetMessage(uint8_t *buf) override
            {
                return static_cast<T *>(this)->SetMessage_Impl(buf);
            }

            uint16_t SetMessage_Impl(uint8_t *buf) { return 0; }

        private:
            Task_CRTP() {}
            friend T;
        };

        class ScheduleBase
        {
        public:
            ScheduleBase();
            ~ScheduleBase();

            int Push(Letter_ptr Letter_ptr);
            virtual void execute_task(Letter_ptr) = 0;

        private:
            void main_loop();

            std::queue<Letter_ptr> schedule_;

            std::mutex lock;
            std::condition_variable CV;
            std::thread main_loop_thr;

            bool should_stop_ = false;
        };
    } // namespace Schedule
} // namespace KAI