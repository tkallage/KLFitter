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

#ifndef KLFITTER_DETECTORCMSDELPHES_H_
#define KLFITTER_DETECTORCMSDELPHES_H_

#include <memory>
#include <string>

#include "KLFitter/DetectorBase.h"

// ---------------------------------------------------------

/**
 * \namespace KLFitter
 * \brief The KLFitter namespace
 */
namespace KLFitter {
/**
  * \class KLFitter::DetectorCMSDelphes
  * \brief A class for describing the CMS detector in Delphes.
  *
  * This class holds the description of the CMS detector in Delphes.
  */
class DetectorCMSDelphes : public DetectorBase {
 public:
  /** \name Constructors and destructors */
  /* @{ */

  /**
    * The default constructor.
    * @param folder The folder with transfer function parameters.
    */
  explicit DetectorCMSDelphes(std::string folder = "");

  /**
    * The (defaulted) destructor.
    */
  ~DetectorCMSDelphes();

  /* @} */
  /** \name Member functions (Get)  */
  /* @{ */

  /**
    * Return the energy resolution of light-jets.
    * @param eta The eta of the particle.
    * @return A pointer to the energy resolution object.
    */
  ResolutionBase* ResEnergyLightJet(double eta = 0.) override;

  /**
    * Return the energy resolution of b-jets.
    * @param eta The eta of the particle.
    * @return A pointer to the energy resolution object.
    */
  ResolutionBase* ResEnergyBJet(double eta = 0.) override;

  /**
    * Return the energy resolution of electrons.
    * @param eta The eta of the particle.
    * @return A pointer to the energy resolution object.
    */
  ResolutionBase* ResEnergyElectron(double eta = 0.) override;

  /**
    * Return the momentum resolution of muons.
    * @param eta The eta of the particle.
    * @return A pointer to the momentum resolution object.
    */
  ResolutionBase* ResEnergyMuon(double eta = 0.) override;

  /**
    * Return the missing ET resolution.
    * @return A pointer to the missing ET resolution.
    */
  ResolutionBase* ResMissingET() override;

  /* @} */

 private:
  /**
    * The energy resolution of light jets for different eta regions.
    */
  std::unique_ptr<ResolutionBase> fResEnergyJet_eta1;
  std::unique_ptr<ResolutionBase> fResEnergyJet_eta2;
  std::unique_ptr<ResolutionBase> fResEnergyJet_eta3;

  /**
    * The energy resolution of electrons for different eta regions.
    */
  std::unique_ptr<ResolutionBase> fResMomentumElectron_eta1;
  std::unique_ptr<ResolutionBase> fResMomentumElectron_eta2;
  std::unique_ptr<ResolutionBase> fResMomentumElectron_eta3;

  /**
    * The momentum resolution of muons for different eta regions.
    */
  std::unique_ptr<ResolutionBase> fResMomentumMuon_eta1;
  std::unique_ptr<ResolutionBase> fResMomentumMuon_eta2;
  std::unique_ptr<ResolutionBase> fResMomentumMuon_eta3;

  /**
    * Missing ET resolution in x and y
    */
  std::unique_ptr<ResolutionBase> fResMissingET_eta1;

  /**
    * The eta binning for jets
    */
  double fJetEtaBin_1;
  double fJetEtaBin_2;
  double fJetEtaBin_3;

  /**
    * The eta binning for electrons
    */
  double fElectronEtaBin_1;
  double fElectronEtaBin_2;
  double fElectronEtaBin_3;

  /**
    * The eta binning for muons
    */
  double fMuonEtaBin_1;
  double fMuonEtaBin_2;
  double fMuonEtaBin_3;

};
}  // namespace KLFitter

#endif  // KLFITTER_DETECTORCMSDELPHES_H_
