#ifndef _EVENT_
#define _EVENT_

#include <string>

/** 
 *  @file   event.h 
 *  @brief  Events definition. Include types and categories
 *  @author Miguel Ravagnani de Carvalho 
 *  @date   2022-20-03 
 **************************************************/

namespace Gaviota
{
    /**
     * @brief Defines the event types
     */
    enum class e_EventType
    {
        NONE = 0,

        EVENT_TYPE_WINDOW_CLOSE,              /*TODO: Fill description*/
        EVENT_TYPE_WINDOW_RESIZE,             /*TODO: Fill description*/
        EVENT_TYPE_WINDOW_AT_FRONT,           /*TODO: Fill description*/
        EVENT_TYPE_WINDOW_AT_BACK,            /*TODO: Fill description*/
        EVENT_TYPE_WINDOW_MOVED,              /*TODO: Fill description*/

        EVENT_TYPE_APP_TICK,                  /*TODO: Fill description*/
        EVENT_TYPE_APP_UPDATE,                /*TODO: Fill description*/
        EVENT_TYPE_APP_RENDER,                /*TODO: Fill description*/

        EVENT_TYPE_KEY_PRESSED,               /*TODO: Fill description*/
        EVENT_TYPE_KEY_RELEASED,              /*TODO: Fill description*/
        EVENT_TYPE_KEY_TYPED,                 /*TODO: Fill description*/

        EVENT_TYPE_MOUSE_BUTTON_PRESSED,      /*TODO: Fill description*/
        EVENT_TYPE_MOUSE_BUTTON_RELEASED,     /*TODO: Fill description*/
        EVENT_TYPE_MOUSE_MOVED,               /*TODO: Fill description*/
        EVENT_TYPE_MOUSE_SCROLL               /*TODO: Fill description*/
    };

    /**
     * @brief Defines the event categories. Each event type can have
     *        multiple categories, so every category is defined as a
     *        bit.
     */
    enum e_EventCategory
    {
        NONE = 0,
        EVENT_CATEGORY_APPLICATION  = BIT(0), /*TODO: Fill description*/
        EVENT_CATEGORY_INPUT        = BIT(1), /*TODO: Fill description*/
        EVENT_CATEGORY_KEYBOARD     = BIT(2), /*TODO: Fill description*/
        EVENT_CATEGORY_MOUSE        = BIT(3), /*TODO: Fill description*/
        EVENT_CATEGORY_BUTTON       = BIT(4)  /*TODO: Fill description*/
    };

/**
 * @brief A type definition macro, that abstract the verbosity of this
 *        operation
 */
#define EVENT_CLASS_TYPE(param_type) \
    static e_EventType GetStaticType() { return e_EventType::param_type; }\
    virutal e_EventType GetEventType() const override { return GetStaticType(); }\
    virutal const char* GetName() const override { return #param_type; }

/**
 * @brief A category definition macro, that abstract the verbosity of this
 *        operation
 */
#define EVENT_CLASS_CATEGORY(param_category)\
    virutal int GetGategoryFlags() const override { return category; }

    /**
    * @brief Base event class to be inherited
    */
    class Event
    {
    public:
        /**
        * @brief Event desctructor
        */
        ~Event() = default;

        /**
         * @brief Holds the handled state of the event
         */
        bool Handled = false;

        /**
         * @brief Returns the event type
         * 
         * @return e_EventType type
         */
        virtual e_EventType GetEventType() const = 0;

        /**
         * @brief Returns the event name
         * 
         * @return const char* name
         */
        virtual const char* GetName() const = 0;

        /**
         * @brief Returns the event category
         * 
         * @return int category
         */
        virtual int GetCategoryFlags() const = 0;

        /**
         * @brief Returns the name of the event to a string
         * 
         * @return std::string name
         */
        virtual std::string ToString() const { return GetName(); }

        /**
         * @brief Checks is the event has the argumnet category
         * 
         * @param param_category Category to be verified
         * @return true if It is in the category
         *         | false if It is not in the category
         */
        bool IsInCategory(e_EventCategory param_category)
        {
            return GetCategoryFlags() & param_category;
        }
    };

    /**
    * @brief Base event dispatcher class
    */
    class EventDispatcher
    {
    public:
        /**
        * @brief Event constructor
        */
        EventDispatcher(Event& param_event) : m_event(param_event){}

        /**
         * @brief Callback function for the dispatcher
         * 
         * @param param_function Function implemented in the callback
         * @return true if event was handled
         *         | false if event was not handeld
         */
        template<typename T, typename F>
        bool Dispatch(const F& param_function)
        {
            if (m_event.GetEventType() == T::GetStaticType())
            {
                m_event.Handled |= param_function(static_cast<T&>(m_event));
                return true;
            }
            return false;
        }
    
    private:
        Event& m_event;
        
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

}
 
#endif //_EVENT_