/*
 * Copyright (c) 2009--2018, the KLFitter developer team
 *
 * This file is part of KLFitter.
 *
 * KLFitter is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * KLFitter is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with KLFitter. If not, see <http://www.gnu.org/licenses/>.
 */

#include "KLFitter/ResGaussDelphes.h"

#include <iostream>
#include "TMath.h"

// ---------------------------------------------------------
KLFitter::ResGaussDelphes::ResGaussDelphes(const char * filename) : KLFitter::ResolutionBase(3) {
  // read parameters from file
  ReadParameters(filename, 3);
}
// ---------------------------------------------------------
KLFitter::ResGaussDelphes::ResGaussDelphes(std::vector<double> const& parameters) : KLFitter::ResolutionBase(parameters) {
  // check number of parameters
  if (parameters.size() != 3) {
    std::cout << "KLFitter::ResGaussDelphes::ResGaussDelphes(). Number of parameters != 3." << std::endl;
    return;
  }
}
// ---------------------------------------------------------1
KLFitter::ResGaussDelphes::~ResGaussDelphes() = default;

// ---------------------------------------------------------
double KLFitter::ResGaussDelphes::GetSigma(double x) {
  return sqrt(fParameters[0] * fParameters[0] * x * x
              + fParameters[1] * fParameters[1] * x
              + fParameters[2] * fParameters[2]);
}

// ---------------------------------------------------------
double KLFitter::ResGaussDelphes::p(double x, double xmeas, bool *good) {
  *good = true;
  double sigma = GetSigma(x);
  return TMath::Gaus(xmeas, x, sigma, true);
}
