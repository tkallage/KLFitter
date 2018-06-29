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

#include "KLFitter/DetectorAtlasDelphes.h"

#include <cmath>
#include <iostream>

#include "KLFitter/ResolutionBase.h"
#include "KLFitter/ResGaussE.h"
#include "KLFitter/ResGauss_MET.h"
#include "TString.h"
// ---------------------------------------------------------
KLFitter::DetectorAtlasDelphes::DetectorAtlasDelphes(std::string folder) : DetectorBase() {
  // Load jet resolutions
  // eta < 1.5
  fJetEtaBin_1 = 1.7;
  fResEnergyJet_eta1 = std::unique_ptr<KLFitter::ResolutionBase>(new KLFitter::ResGaussE{Form("%s/par_energy_jets_eta1.txt", folder.c_str())});
  // 1.5 < abs(eta) < 3.2
  fJetEtaBin_2 = 3.2;
  fResEnergyJet_eta2 = std::unique_ptr<KLFitter::ResolutionBase>(new KLFitter::ResGaussE{Form("%s/par_energy_jets_eta2.txt", folder.c_str())});
  // 3.2 < abs(eta) < 4.9
  fJetEtaBin_3 = 4.9;
  fResEnergyJet_eta3 = std::unique_ptr<KLFitter::ResolutionBase>(new KLFitter::ResGaussE{Form("%s/par_energy_jets_eta3.txt", folder.c_str())});

  // Load electron resolutions
  // abs(eta) < 0.5
  fElectronEtaBin_1 = 0.5;
  fResMomentumElectron_eta1 = std::unique_ptr<KLFitter::ResolutionBase>(new KLFitter::ResGaussE{Form("%s/par_pt_electrons_eta1.txt", folder.c_str())});
  // 0.5 < abs(eta) < 1.5
  fElectronEtaBin_2 = 1.5;
  fResMomentumElectron_eta2 = std::unique_ptr<KLFitter::ResolutionBase>(new KLFitter::ResGaussE{Form("%s/par_pt_electrons_eta2.txt", folder.c_str())});
  // 1.5 < abs(eta) < 2.5
  fElectronEtaBin_3 = 2.5;
  fResMomentumElectron_eta3 = std::unique_ptr<KLFitter::ResolutionBase>(new KLFitter::ResGaussE{Form("%s/par_pt_electrons_eta3.txt", folder.c_str())});

  // Load muon resolutions
  // abs(eta) < 0.5
  fMuonEtaBin_1 = 0.5;
  fResMomentumMuon_eta1 = std::unique_ptr<KLFitter::ResolutionBase>(new KLFitter::ResGaussE{Form("%s/par_pt_muons_eta1.txt", folder.c_str())});
  // 0.5 < abs(eta) < 1.5
  fMuonEtaBin_2 = 1.5;
  fResMomentumMuon_eta2 = std::unique_ptr<KLFitter::ResolutionBase>(new KLFitter::ResGaussE{Form("%s/par_pt_muons_eta2.txt", folder.c_str())});
  // 1.5 < abs(eta) < 2.5
  fMuonEtaBin_3 = 2.5;
  fResMomentumMuon_eta3 = std::unique_ptr<KLFitter::ResolutionBase>(new KLFitter::ResGaussE{Form("%s/par_pt_muons_eta3.txt", folder.c_str())});

  // Load missing et resolution
  fResMissingET_eta1 = std::unique_ptr<KLFitter::ResolutionBase>(new KLFitter::ResGauss_MET{Form("%s/par_misset.txt", folder.c_str())});

  // default settings
  fResEnergyLightJet = fResEnergyJet_eta1.get();
  fResEnergyBJet = fResEnergyJet_eta1.get();
  fResEnergyGluonJet = fResEnergyJet_eta1.get();
  fResEnergyElectron = fResMomentumElectron_eta1.get();
  fResEnergyPhoton = fResMomentumElectron_eta1.get();
  fResEnergyMuon = fResMomentumMuon_eta1.get();
  fResMissingET = fResMissingET_eta1.get();
}

// ---------------------------------------------------------
KLFitter::DetectorAtlasDelphes::~DetectorAtlasDelphes() = default;

// ---------------------------------------------------------
KLFitter::ResolutionBase * KLFitter::DetectorAtlasDelphes::ResEnergyLightJet(double eta) {
  if (fabs(eta) < fJetEtaBin_1) {
    fResEnergyLightJet = fResEnergyJet_eta1.get();
  } else if (fabs(eta) < fJetEtaBin_2) {
    fResEnergyLightJet = fResEnergyJet_eta2.get();
  } else if (fabs(eta) < fJetEtaBin_3) {
    fResEnergyLightJet = fResEnergyJet_eta3.get();
  } else {
    std::cout << "KLFitter::DetectorAtlasDelphes::ResEnergyLightJet(). Eta range exceeded." << std::endl;
    return 0;
  }

  return fResEnergyLightJet;
}

// ---------------------------------------------------------
KLFitter::ResolutionBase * KLFitter::DetectorAtlasDelphes::ResEnergyBJet(double eta) {
  if (fabs(eta) < fJetEtaBin_1) {
    fResEnergyBJet = fResEnergyJet_eta1.get();
  } else if (fabs(eta) < fJetEtaBin_2) {
    fResEnergyBJet = fResEnergyJet_eta2.get();
  } else if (fabs(eta) < fJetEtaBin_3) {
    fResEnergyBJet = fResEnergyJet_eta3.get();
  } else {
    std::cout << "KLFitter::DetectorAtlasDelphes::ResEnergyBJet(). Eta range exceeded." << std::endl;
    return 0;
  }

  return fResEnergyBJet;
}

// ---------------------------------------------------------
KLFitter::ResolutionBase * KLFitter::DetectorAtlasDelphes::ResEnergyElectron(double eta) {
  if (fabs(eta) < fElectronEtaBin_1) {
    fResEnergyElectron = fResMomentumElectron_eta1.get();
  } else if (fabs(eta) < fElectronEtaBin_2) {
    fResEnergyElectron = fResMomentumElectron_eta2.get();
  } else if (fabs(eta) < fElectronEtaBin_3) {
    fResEnergyElectron = fResMomentumElectron_eta3.get();
  } else {
    std::cout << "KLFitter::DetectorAtlasDelphes::ResEnergyElectron(). Eta range exceeded." << std::endl;
    return 0;
  }
  return fResEnergyElectron;
}

// ---------------------------------------------------------
KLFitter::ResolutionBase * KLFitter::DetectorAtlasDelphes::ResEnergyMuon(double eta) {
  if (fabs(eta) < fMuonEtaBin_1) {
    fResEnergyMuon = fResMomentumMuon_eta1.get();
  } else if (fabs(eta) < fMuonEtaBin_2) {
    fResEnergyMuon = fResMomentumMuon_eta2.get();
  } else if (fabs(eta) < fMuonEtaBin_3) {
    fResEnergyMuon = fResMomentumMuon_eta3.get();
  } else {
    std::cout << "KLFitter::DetectorAtlasDelphes::ResEnergyMuon(). Eta range exceeded." << std::endl;
    return 0;
  }

  return fResEnergyMuon;
}

// ---------------------------------------------------------
KLFitter::ResolutionBase * KLFitter::DetectorAtlasDelphes::ResMissingET() {
  return fResMissingET_eta1.get();
}
// ---------------------------------------------------------
