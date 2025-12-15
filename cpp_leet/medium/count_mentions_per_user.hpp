#include <vector>
#include <string>
#include <memory>
#include <iostream>

class Solution
{
  private:

    class Event
    {
      private:

        enum class EventType : int
        {
          MESSAGE, // when a message is sent
          OFFLINE, // when a user goes offline
          ONLINE   // when a user goes online
        };

        int timeStamp;

      public:

        Event
        (
          const int _timeStamp
        ) noexcept : timeStamp(_timeStamp)
        {
        }

        Event
        (
          const std::string _timeStamp
        )
        {
          try
          {
            this->
          }
          catch(const std::exception& e)
          {
            std::cerr << e.what() << '\n';
            throw e;
          }
        }

        virtual Solution::Event::EventType getType
        (
        ) const noexcept = 0;

        virtual bool operator<
        (
          const Event& other\
        ) const noexcept = 0;
    };

    class MessageEvent final : public Event
    {
      private:

      std::vector<int> mentions;

      public:
    };

  public:

    std::vector<int> countMentions
    (
      int numberOfUsers,
      std::vector<std::vector<std::string>>& events
    );
};

std::vector<int> Solution::countMentions
(
  int numberOfUsers,
  std::vector<std::vector<std::string>>& events
)
{

}