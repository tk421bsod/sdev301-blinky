#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>

int increment_component(int current_value)
{
    if (current_value == 31)
    {
        return 0;
    }
    return current_value + 1;
}

int main()
{
    bn::core::init();
    bn::color colors[3] = {bn::color(0, 0, 31), bn::color(0, 31, 0), bn::color(31, 0, 0)};
    int current_color_index = 0;
    int new_component_value = 0;
    bn::backdrop::set_color(colors[0]);
    while (true)
    {
        if (bn::keypad::a_pressed())
        {
            if (current_color_index == 2)
            {
                current_color_index = 0; // Wrap around color index to first color in array
            }
            else
            {
                current_color_index++;
            }
            bn::backdrop::set_color(colors[current_color_index]);
        }
        if (bn::keypad::left_pressed())
        {
            new_component_value = increment_component(colors[current_color_index].red());
            colors[current_color_index].set_red(new_component_value);
            bn::backdrop::set_color(colors[current_color_index]);
        }
        if (bn::keypad::up_pressed())
        {
            new_component_value = increment_component(colors[current_color_index].green());
            colors[current_color_index].set_green(new_component_value);
            bn::backdrop::set_color(colors[current_color_index]);
        }
        if (bn::keypad::right_pressed())
        {
            new_component_value = increment_component(colors[current_color_index].blue());
            colors[current_color_index].set_blue(new_component_value);
            bn::backdrop::set_color(colors[current_color_index]);
        }
        bn::core::update();
    }
}