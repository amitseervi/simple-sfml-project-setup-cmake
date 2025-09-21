#ifndef __HEADER_RIGNIS_SCREEN__
#define __HEADER_RIGNIS_SCREEN__
namespace rignis
{
    class GameScreen
    {
    public:
        void onCreate();
        void onDestroy();
        void onPause();
        void onResume();
        void onResize();
        void onUpdate(const float delta);

    private:
    };
};
#endif