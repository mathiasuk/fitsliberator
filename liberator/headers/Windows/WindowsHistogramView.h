// The ESA/ESO/NASA FITS Liberator - http://code.google.com/p/fitsliberator
//
// Copyright (c) 2004-2010, ESA/ESO/NASA.
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the names of the European Space Agency (ESA), the European 
//       Southern Observatory (ESO) and the National Aeronautics and Space 
//       Administration (NASA) nor the names of its contributors may be used to
//       endorse or promote products derived from this software without specific
//       prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL ESA/ESO/NASA BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// =============================================================================
//
// The ESA/ESO/NASA FITS Liberator uses NASA's CFITSIO library, libtiff, 
// TinyXML, Boost C++ Libraries, Object Access Library and Intel Threading 
// Building Blocks.
//
// =============================================================================
//
// Project Executive:
//   Lars Lindberg Christensen
//
// Technical Project Manager:
//   Lars Holm Nielsen
//
// Developers:
//   Kaspar Kirstein Nielsen & Teis Johansen
// 
// Technical, scientific support and testing: 
//   Robert Hurt
//   Davide De Martin
//
// =============================================================================
#ifndef __WINDOWSHISTOGRAMVIEW_H__
#define __WINDOWSHISTOGRAMVIEW_H__

#include "Dialog.h"
#include "HistogramView.h"
#include "EventSink.h"
#include "HistogramControl.h"
#include "SliderControl.h"
#include "StretchModel.h"
#include "NumericTextbox.h"

namespace FitsLiberator {
    namespace Windows {
        class MainDialog;

        /**
         * Implements the interface between the Windows GUI and HistogramView.
         */ 
        class WindowsHistogramView : public FitsLiberator::Modelling::HistogramView, public EventSink {
            public:
				WindowsHistogramView(
                    FitsLiberator::Modelling::HistogramModel&,                    
                    FitsLiberator::Modelling::ToolModel&,
                    FitsLiberator::Modelling::StatisticsModel&,
                    FitsLiberator::Modelling::StretchModel&,
                    FitsLiberator::Modelling::OptionsModel&,
					FitsLiberator::Modelling::HistogramController&,
					FitsLiberator::Modelling::FlowController&
                    
                    );

                virtual Void OnInit( Dialog*, Int );
                virtual Void OnCommand( WPARAM, LPARAM );
                virtual Void OnNotify( Int, LPNMHDR );
                virtual Void OnScroll( WPARAM, LPARAM );
            protected:
			    virtual Void drawHistogram();
			    virtual Void setHistogramMin( Double );
			    virtual Void setHistogramMax( Double );
			    virtual Void setCurrentToolFunction( FitsLiberator::Modelling::ToolTypeFunction );
				virtual Void setWhiteLevel(Double);
			    virtual Void setBlackLevel(Double);
            private:
                Void OnNumericGotFocus( UInt );
                Void OnNumericLostFocus( UInt );
                Void OnNumericArrow( UInt, UInt );
                Void OnNumericEnter( UInt );

                MainDialog*       mainDialog;
                
				HWND            hWndWhiteSpin;      ///< White level up/down
                HWND            hWndBlackSpin;      ///< Black level up/down
				NumericTextbox  whiteLevel;         ///< White level edit
                NumericTextbox  blackLevel;         ///< Black level edit

                static const RECT histogramBounds;  ///< Boundaries of the histogram control.
                HistogramControl  histogramControl; ///< Histogram custom control.
                SliderControl     sliderControl;    ///< Histogram sliders
                Window            minLabel;         ///< Histogram minimum label
                Window            maxLabel;         ///< Histogram maximum label
        };  
    }
}

#endif //__WINDOWSHISTOGRAMVIEW_H__
