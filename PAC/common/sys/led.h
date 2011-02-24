/// @file led.h
/// @brief ������ �� ������������ �����������.
/// 
/// @author  ������ ������� ���������.
///
/// @par �������� �������� �������������:
/// @c DEBUG    - ���������� c ������� ���������� ���������� � �������.@n@n
/// 
/// @par ������� ������:
/// @$Rev: 220 $.\n
/// @$Author: id $.\n
/// @$Date:: 2011-02-15 16:58:56#$.

#ifndef LED_H
#define LED_H

//-----------------------------------------------------------------------------
/// @brief ������ � �������� ������������. ������������ ���������� ��
/// ���������� ���������� �������.
class led
    {
    public:
        enum COLOUR
            {
            C_GREEN = 1,
            C_YELLOW,
            C_RED
            };

        enum LEDS_NAMES
            {
            L_ALL = 1,
            L_STATUS,
            L_SERVICE,
            L_USER
            };

        /// @brief ��������� �������� ����������.
        ///
        /// @param led       - ����.
        /// @param led_color - ����.
        virtual void on( LEDS_NAMES led, COLOUR led_color ) = 0;

        /// @brief ���������� �������� ����������.
        virtual void off( LEDS_NAMES led ) = 0;

        /// @brief ��������� ������� �������� ����������.
        ///
        /// @param led       - ����.
        /// @param led_color - ����.
        virtual void blink( LEDS_NAMES led, COLOUR led_color ) = 0;
    };
//-----------------------------------------------------------------------------
led* get_led();
//-----------------------------------------------------------------------------

#endif // LED_H