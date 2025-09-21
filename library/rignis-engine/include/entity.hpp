#ifndef __HEADER_RIGNIS_ENTITY__
#define __HEADER_RIGNIS_ENTITY__
namespace rignis
{
    class GameEntity
    {
    public:
        void pause();
        void resume();
        void destroy();
        void create();
        bool isActive();
        bool isDestroyed();

    private:
    };
};
#endif