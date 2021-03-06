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

#ifndef KLFITTER_LIKELIHOODTOPLEPTONJETSUDSEP_H_
#define KLFITTER_LIKELIHOODTOPLEPTONJETSUDSEP_H_

#include <iostream>

class TH1F;
class TH2F;
class TLorentzVector;

namespace KLFitter {
  class ResolutionBase;
}

#include "KLFitter/LikelihoodTopLeptonJets.h"

// ---------------------------------------------------------

/**
 * \namespace KLFitter
 * \brief The KLFitter namespace
 */
namespace KLFitter {
/**
  * \class KLFitter::LikelihoodTopLeptonJetsUDSep
  * \brief A class implementing a likelihood for the ttbar lepton+jets channel.
  *
  * This class represents a likelihood for the ttbar into lepton+jets.
  */
class LikelihoodTopLeptonJetsUDSep : public KLFitter::LikelihoodTopLeptonJets {
 public:
  /**
    * Enumerate for lJet reweighting methods
    */
  enum LJetSeparationMethod{
    kNone,
    kPermReweight,
    kPermReweight2D
  };

  /** \name Constructors and destructors */
  /* @{ */

  /**
    * The default constructor.
    */
  LikelihoodTopLeptonJetsUDSep();

  /**
    * The (defaulted) destructor.
    */
  ~LikelihoodTopLeptonJetsUDSep();

  /* @} */

  /**
    * Define the parameters of the fit.
    */
  void DefineParameters() override;

  /**
    * Return the log of the event probability fof the current
    * combination
    * @return The event probability
    */
  double LogEventProbability() override;

  /**
    * Return the contribution from b tagging to the log of the
    * event probability for the current combination
    * @return The event probability contribution
    */
  double LogEventProbabilityBTag() override;

  /**
    * Return the contribution from pT and b tag weight probability (by LJetSeparationMethod)
    * to the log of the event probability for the current combination
    * @return The event probability contribution
    */
  double LogEventProbabilityLJetReweight();

  /**
    * Returns the probability of a jet to have the pT of an up type jet.
    * @return The probability.
    */
  double UpJetPt(double pt);

  /**
    * Returns the probability of a jet to have the pT of an down type jet.
    * @return The probability.
    */
  double DownJetPt(double pt);

  /**
    * Returns the probability of a jet to have the pT of an b type jet.
    * @return The probability.
    */
  double BJetPt(double pt);

  /**
    * Returns the probability of a jet to have the tag weight of an up type jet.
    * @return The probability.
    */
  double UpJetTagWeight(double tagweight);

  /**
    * Returns the probability of a jet to have the tag weight of an down type jet.
    * @return The probability.
    */
  double DownJetTagWeight(double tagweight);

  /**
    * Returns the probability of a jet to have the tag weight of an b type jet.
    * @return The probability.
    */
  double BJetTagWeight(double tagweight);
  //
  /**
    * Returns the probability of a jet to have the tag weight and pT of an up type jet.
    * @return The probability.
    */
  double UpJetProb(double tagweight, double pt);

  /**
    * Returns the probability of a jet to have the tag weight and pT of an down type jet.
    * @return The probability.
    */
  double DownJetProb(double tagweight, double pt);

  /**
    * Returns the probability of a jet to have the tag weight and pT of an b type jet.
    * @return The probability.
    */
  double BJetProb(double tagweight, double pt);
  //

  /**
    * Set histogram for pT distribution of up jets (reco level).
    * @param hist Pointer to histogram.
    * @return An error flag.
    */
  int SetUpJetPtHisto(TH1F* hist) { fUpJetPtHisto = hist; return 1; }

  /**
    * Set histogram for pT distribution of down jets (reco level).
    * @param hist Pointer to histogram.
    * @return An error flag.
    */
  int SetDownJetPtHisto(TH1F* hist) { fDownJetPtHisto = hist; return 1; }

  /**
    * Set histogram for pT distribution of b jets (reco level).
    * @param hist Pointer to histogram.
    * @return An error flag.
    */
  int SetBJetPtHisto(TH1F* hist) { fBJetPtHisto = hist; return 1; }

  /**
    * Set histogram for tag weight distribution of up type jets.
    * @param hist Pointer to histogram.
    * @return An error flag.
    */
  int SetUpJetTagWeightHisto(TH1F* hist) { fUpJetTagWeightHisto = hist; return 1; }

  /**
    * Set histogram for tag weight distribution of down type jets.
    * @param hist Pointer to histogram.
    * @return An error flag.
    */
  int SetDownJetTagWeightHisto(TH1F* hist) { fDownJetTagWeightHisto = hist; return 1; }

  /**
    * Set histogram for tag weight distribution of b jets.
    * @param hist Pointer to histogram.
    * @return An error flag.
    */
  int SetBJetTagWeightHisto(TH1F* hist) { fBJetTagWeightHisto = hist; return 1; }

  /**
    * Set a flag. If flag is true the permutations are reweighted with the pT and tag weight probabilities.
    * @param flag The flag.
    */
  void SetLJetSeparationMethod(KLFitter::LikelihoodTopLeptonJetsUDSep::LJetSeparationMethod flag) { fLJetSeparationMethod = flag; }

  /**
    * Check if the permutation is LH invariant.
    * @return Permutation of the invariant partner, -1 if there is no one.
    */
  int LHInvariantPermutationPartner(int iperm, int nperms, int *switchpar1, int *switchpar2) override;

  /**
    * Set histogram for tag weight distribution of up type jets.
    * @param hist Pointer to histogram.
    * @return An error flag.
    */
  int SetUpJet2DWeightHisto(TH2F* hist) { fUpJet2DWeightHisto = hist; return 1; }

  /**
    * Set histogram for tag weight distribution of down type jets.
    * @param hist Pointer to histogram.
    * @return An error flag.
    */
  int SetDownJet2DWeightHisto(TH2F* hist) { fDownJet2DWeightHisto = hist; return 1; }

  /**
    * Set histogram for tag weight distribution of b jets.
    * @param hist Pointer to histogram.
    * @return An error flag.
    */
  int SetBJet2DWeightHisto(TH2F* hist) { fBJet2DWeightHisto = hist; return 1; }

 protected:
  /** \name Member functions (misc)  */
  /* @{ */

  /**
    * Define the model particles
    * @return An error code.
    */
  int DefineModelParticles() override;

  /**
    * Remove invariant particle permutations.
    * @return An error code.
    */
  int RemoveInvariantParticlePermutations() override;

  /**
    * Remove forbidden particle permutations.
    * @return An error code.
    */
  int RemoveForbiddenParticlePermutations() override { return 1; }

  /**
    * A flag for using an additional reweighting of the permutations with the pT and tag weight probability (default: false);
    */
  KLFitter::LikelihoodTopLeptonJetsUDSep::LJetSeparationMethod fLJetSeparationMethod;

  /**
    * A pointer to the histogram of the up type jet pT distribution.
    */
  TH1F* fUpJetPtHisto;

  /**
    * A pointer to the histogram of the down type jet pT distribution.
    */
  TH1F* fDownJetPtHisto;

  /**
    * A pointer to the histogram of the down b jet pT distribution.
    */
  TH1F* fBJetPtHisto;

  /**
    * A pointer to the histogram of the up quark tag weight distribution.
    */
  TH1F* fUpJetTagWeightHisto;

  /**
    * A pointer to the histogram of the down quark tag weight distribution.
    */
  TH1F* fDownJetTagWeightHisto;

  /**
    * A pointer to the histogram of the up b tag weight distribution.
    */
  TH1F* fBJetTagWeightHisto;

  /**
    * A pointer to the 2d histogram "tag weight vs. pT for upQuarks"
    */
  TH2F* fUpJet2DWeightHisto;

  /**
    * A pointer to the 2d histogram "tag weight vs. pT for downQuarks"
    */
  TH2F* fDownJet2DWeightHisto;

  /**
    * A pointer to the 2d histogram "tag weight vs. pT for bQuarks"
    */
  TH2F* fBJet2DWeightHisto;

  /* @} */
};
}  // namespace KLFitter

#endif  // KLFITTER_LIKELIHOODTOPLEPTONJETSUDSEP_H_
