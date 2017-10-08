/*----------------------------------------------------------------------------
 ChucK Concurrent, On-the-fly Audio Programming Language
   Compiler and Virtual Machine
 
 Copyright (c) 2003 Ge Wang and Perry R. Cook.  All rights reserved.
   http://chuck.stanford.edu/
   http://chuck.cs.princeton.edu/
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 U.S.A.
 -----------------------------------------------------------------------------*/

//-----------------------------------------------------------------------------
// file: chuck.h
// desc: chuck engine header; VM + compiler + state; no audio I/O
//       REFACTOR-2017
//
// author: Ge Wang (http://www.gewang.com/)
// date: fall 2017
//
// additional authors:
//         Jack Atherton (lja@ccrma.stanford.edu)
//         Spencer Salazar (spencer@ccrma.stanford.edu)
//-----------------------------------------------------------------------------
#include "chuck.h"
//#include "chuck_errmsg.h"


ChucK * the_chuck;

extern "C" {
void chuckscript_init( int srate, int inchannels, int outchannels )
{
    the_chuck = new ChucK();
    the_chuck->setParam( CHUCK_PARAM_SAMPLE_RATE, (t_CKINT) srate );
    the_chuck->setParam( CHUCK_PARAM_INPUT_CHANNELS, (t_CKINT) inchannels  );
    the_chuck->setParam( CHUCK_PARAM_OUTPUT_CHANNELS, (t_CKINT) outchannels );
    the_chuck->setParam( CHUCK_PARAM_CHUGIN_ENABLE, (t_CKINT) 0 );
    the_chuck->init();
    the_chuck->start();
}


void chuckscript_run( float * inbuffer, float * outbuffer, int numFrames )
{
    the_chuck->run( inbuffer, outbuffer, numFrames );
}

void chuckscript_compilecode( char * code )
{
    the_chuck->compileCode( std::string( code ), "", 1 );
}

}



