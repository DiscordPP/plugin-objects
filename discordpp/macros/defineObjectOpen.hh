//
// Created by Aidan on 9/2/2021.
//

#include <memory>

#ifdef DEFINE_OBJECT_OPEN
#error There is already an open Object definition
#endif
#define DEFINE_OBJECT_OPEN

#ifndef Bot
#error The call needs to be in a bot
#endif
#ifndef Class
#error The object needs a class name
#endif

class Class
#ifdef Parent
    : public Parent
#else
    : public std::enable_shared_from_this<Class>
#endif
{
    friend Bot;

#ifndef Parent
  protected:
    explicit Class(BotStruct *bot) : bot_(bot) {}

    // https://stackoverflow.com/a/32172486
    template <typename Derived> std::shared_ptr<Derived> shared_from_base() {
        return std::static_pointer_cast<Derived>(shared_from_this());
    }
#endif
