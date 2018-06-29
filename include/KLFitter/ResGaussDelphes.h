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

#ifndef KLFITTER_RESGAUSSDELPHES_H_
#define KLFITTER_RESGAUSSDELPHES_H_

#include <vector>
#include "KLFitter/ResolutionBase.h"

// ---------------------------------------------------------

/**
 * \namespace KLFitter
 * \brief The KLFitter namespace
 */
namespace KLFitter {
/**
  * \class KLFitter::ResGaussDelphes
  * \brief A class describing a Gaussian resolution.
  *
  * This class offers a simple parameterization of a resolution. The
  * parameterization is a Gaussian with a width parametrized
  * as a function of the true parameter.
  */
class ResGaussDelphes : public ResolutionBase {
 public:
  /** \name Constructors and destructors */
  /* @{ */

  /**
    * The default constructor.
    */
  explicit ResGaussDelphes(const char * filename);

  /**
    * A constructor.
    * @param sigma The width of the Gaussian.
    */
  explicit ResGaussDelphes(double sigma);

  /**
    * A constructor.
    * @param sigma The width of the Gaussian.
    */
  explicit ResGaussDelphes(std::vector<double> const& parameters);

  /**
    * The (defaulted) destructor.
    */
  ~ResGaussDelphes();

  /* @} */
  /** \name Member functions (Get)  */
  /* @{ */

  /**
    * Return the width of the TF depending on the value of energy x.
    * Used to adjust the range of the fit parameter that correspond to the TF.
    * @param x true energy as parameter of the TF.
    * @return The width.
    */
  double GetSigma(double x) override;

  /**
    * Return the probability of the true value of x given the
    * measured value, xmeas.
    * @param x The true value of x.
    * @param xmeas The measured value of x.
    * @param good False if problem with TF.
    * @param par Optional additional parameter (SumET in case of MET TF).
    * @return The probability.
    */
  double p(double x, double xmeas, bool *good) override;

  /* @} */
};
}  // namespace KLFitter

#endif  // KLFITTER_RESGAUSSDELPHES_H_
