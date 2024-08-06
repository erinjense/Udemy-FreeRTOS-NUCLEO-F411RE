
#ifndef INCLUDE_LED_TEMPLATE_H_
#define INCLUDE_LED_TEMPLATE_H_

extern "C" {
#include <FreeRTOS.h>
#include <task.h>
}

template<typename port_type, typename pin_type>
class led_template
{
public:
    led_template(port_type port, pin_type pin) : port(port), pin(pin)
    {
        GPIO_InitTypeDef GPIO_InitStruct = {
        		.Pin = pin,
        		.Mode = GPIO_MODE_OUTPUT_PP,
				.Pull = GPIO_NOPULL,
				.Speed = GPIO_SPEED_FREQ_LOW,
        };
        HAL_GPIO_Init(port, &GPIO_InitStruct);
    }

    void toggle() const
    {
		HAL_GPIO_TogglePin(port, pin);
    }

    void on() const
    {
    	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
    }

    void off() const
    {
    	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
    }

private:
    GPIO_TypeDef * port;
    uint16_t pin;
};

#endif /* INCLUDE_LED_TEMPLATE_H_ */
