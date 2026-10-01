#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>

int main()
{
    bn::core::init();
    bn::color colors[3] = {bn::color(0, 0, 31), bn::color(0, 31, 0), bn::color(31, 0, 0)};
    int current_color = 0;
    bn::backdrop::set_color(colors[0]);
    while (true)
    {
        if (bn::keypad::a_pressed())
        {
            if (current_color == 2)
            {
                current_color = 0; // Wrap around color index to first color in array
            }
            else
            {
                current_color++;
            }
            bn::backdrop::set_color(colors[current_color]);
        }

        bn::core::update();
    }
}