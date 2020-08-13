#include "udp_node/schedule/schedule_base.h"

namespace KAI
{
    namespace Schedule
    {

        ScheduleBase::ScheduleBase()
        {
            main_loop_thr = std::thread(&ScheduleBase::main_loop, this);
        }

        ScheduleBase::~ScheduleBase()
        {
            std::queue<Letter_ptr> empty;
            empty.swap(schedule_);
            CV.notify_all();
            should_stop_ = true;
            if (main_loop_thr.joinable())
                main_loop_thr.join();
        }

        std::size_t ScheduleBase::Push(Letter_ptr letter_ptr)
        {
            schedule_.push(letter_ptr);
            CV.notify_one();
            return schedule_.size();
        }

        void ScheduleBase::main_loop()
        {
            std::unique_lock<std::mutex> lk(lock);
            while (!should_stop_)
            {
                CV.wait(lk);
                while (!schedule_.empty())
                {
                    Letter_ptr Letter_ptr = schedule_.front();
                    execute_task(Letter_ptr);
                    schedule_.pop();
                }
            }
        }
    } // namespace Schedule
} // namespace KAI