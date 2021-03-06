/*
 * This file is part of the libk8055 Library.
 *
 * The libk8055 Library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * The libk8055 Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://opensource.org/licenses/
 *
 * Copyright (C) 2011 by Jérémy Zurcher
 *
 */

#ifndef K8055_CPP_H
#define K8055_CPP_H 1

#include "k8055.h"

class K8055 {
    public:
        K8055();
        ~K8055();

        int read( void );
        int write( void );

        int digital_outputs( void );
        int digital_output_1( void );
        int digital_output_2( void );
        int digital_output_3( void );
        int digital_output_4( void );
        int digital_output_5( void );
        int analog_output_1( void );
        int analog_output_2( void );
        int digital_input_1( void );
        int digital_input_2( void );
        int digital_input_3( void );
        int digital_input_4( void );
        int digital_input_5( void );
        int analog_input_1( void );
        int analog_input_2( void );
        int counter_1( void );
        int counter_2( void );

        static char* Version( void );
        static int SearchDevices( void );

        int OpenDevice( int board_address );
        int CloseDevice();

        int SetAnalogChannel( int channel );
        int ClearAnalogChannel( int channel );
        int ReadAnalogChannel( int channel );
        int WriteAnalogChannel( int channel, int data );

        int SetAllAnalog();
        int ClearAllAnalog();
        int ReadAllAnalog( int* data1, int* data2 );
        int WriteAllAnalog( int data1,int data2 );

        int SetDigitalChannel( int channel );
        int ClearDigitalChannel( int channel );
        int ReadDigitalChannel( int channel );

        int SetAllDigital();
        int ClearAllDigital();
        int ReadAllDigital();
        int WriteAllDigital( int data );

        int WriteAllOutputs( int digital, int analog1, int analog2 );
        int ReadAllInputs ( int* digital, int* analog1, int* analog2, int* counter1, int* counter2 );

        int ResetCounter( int counter );
        int ReadCounter( int counter );

        int SetCounterDebounceTime( int counter, int debounce_time );

    private:
        struct k8055_dev dev;
};

#endif // K8055_CPP_H
