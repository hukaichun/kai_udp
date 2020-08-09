#pragma once

#include <queue>
#include <memory>
#include <cstdint>

#include <mutex>
#include <condition_variable>
#include <thread>


#include <iostream>


namespace KAI
{
    namespace Schedule
    {
        /**
         * Letter Base Class
        */
        class LetterBase
        {
        public:
            virtual uint16_t SetMessage(uint8_t *buf) = 0;
        };

        /**
         * Rename pointer
        */
        using Letter_ptr = std::shared_ptr<LetterBase>;

        /**
         * CRPT_Base Class
        */
        template <typename T>
        class Letter_CRTP : public LetterBase
        {
        public:
            uint16_t SetMessage(uint8_t *buf) final
            {
                return static_cast<T *>(this)->SetMessage_Impl(buf);
            }

            inline uint16_t SetMessage_Impl(uint8_t *buf) {
                std::cout << "Default Impl, do nothing" << std::endl;
                return 0;
            };

        private:
            Letter_CRTP() {}
            friend T;
        };

        /**
         * Schedule Base Class
         *   ScheduleBase()     // constructer, starting main_loop at begining
        */
        class ScheduleBase
        {
        public:
            ScheduleBase();
            ~ScheduleBase();

            int Push(Letter_ptr letter_ptr);

        protected:
            inline void execute_task(Letter_ptr) {
                throw std::string("Not Implementation Error!");
                return;
            }

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