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
#ifndef __STATISTICSMODEL_H__
#define __STATISTICSMODEL_H__

#include "FitsLiberator.h"
#include "Observer.h"
#include "FitsStatisticsCache.h"
#include "StatisticsCacheHandler.h"
#include "Stretch.h"
#include "Plane.h"

using namespace FitsLiberator::Caching;
using namespace FitsLiberator::Engine;

namespace FitsLiberator {
	namespace Modelling {

		/**
		*	Implements a class that contains
		*	all the statistics information
		*/
	class StatisticsModel : public Model {
		public:
			StatisticsModel( ChangeManager *chman );
			~StatisticsModel( );
			
			Double getRealMin();
			Double getRealMax();
			Double getRealMean();
			Double getRealMedian();
			Double getRealSTDEV();

			Double getScaledMin();
			Double getScaledMax();
			Double getScaledMean();
			Double getScaledMedian();
			Double getScaledSTDEV();

			Double getStretchMin();
			Double getStretchMax();
			Double getStretchMean();
			Double getStretchMedian();
			Double getStretchSTDEV();

			Bool useCache(Stretch& stretch, Plane& plane, Double* min, Double* max, Double* mean,
						  Double* stdev, Double* median, Vector<Double>& histogram, Double* maxBinCount );

			Void storeCache( Stretch& stretch , Vector<Double>& histo, Double maxBinCount, Plane& plane, Double background, Double scale,
								 Double max, Double min, Double mean, Double median, Double stdev);
			Void clearCache();

		private:
			Double realMin;
			Double realMax;
			Double realMean;
			Double realMedian;
			Double realSTDEV;
			
			Double scaledMin;
			Double scaledMax;
			Double scaledMean;
			Double scaledMedian;
			Double scaledSTDEV;

			Double stretchMin;
			Double stretchMax;
			Double stretchMean;
			Double stretchMedian;
			Double stretchSTDEV;

			StatisticsCacheHandler* cacheHandler;

			friend class StatisticsController;
	};
	
		
	} // end namespace Modelling
} // end namespace FitsLiberator

#endif //__STATISTICSMODEL_H__