#ifndef _MY_CLASS_
#define _MY_CLASS_

/** 
 *  @file   application.h 
 *  @brief  Class description
 *  @author Miguel Ravagnani de Carvalho 
 *  @date   YYYY-DD-MM 
 **************************************************/

namespace Gaviota
{
    /**
     * @brief Class description
     */
    class Application
    {
    public:
        /*Constructors--------------------------------*/
        /**
         * @brief Application constructor
         */
        Application();

        /**
         * @brief Application desctructor
         */
        virtual ~Application();

        /*Methods-------------------------------------*/
        /**
         * @brief Runs the application
         */
        void Run();

    private:
        /*--------------------------------------------*/
        /*Member variables starting with m_*/
    };
}

#endif //_MY_CLASS_
 