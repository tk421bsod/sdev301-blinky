#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>

int main()
{
    bn::core::init();
    bn::color pure_blue = bn::color(0, 0, 31);
    bn::color pure_green = bn::color(0, 31, 0);
    bn::color pure_red = bn::color(31, 0, 0);
    bn::backdrop::set_color(pure_blue);
    while (true)
    {
        if (bn::keypad::a_pressed())
        {
            bn::color current_color = bn::backdrop::color().value();
            if (current_color == pure_blue)
            {
                bn::backdrop::set_color(pure_green);
            }
            else if (current_color == pure_green)
            {
                bn::backdrop::set_color(pure_red);
            }
            else if (current_color == pure_red)
            {
                bn::backdrop::set_color(pure_blue);
            }
        }

        bn::core::update();
    }
}