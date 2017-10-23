// -*-Mode: C++;-*-

#ifndef PDD_TPCFRAGMENT_HH
#define PDD_TPCFRAGMENT_HH

/* ---------------------------------------------------------------------- *//*!
 *
 *  @file     TpcFragment.hh
 *  @brief    Proto-Dune Online/Offline Data Tpc Access Routines
 *  @verbatim
 *                               Copyright 2017
 *                                    by
 *
 *                       The Board of Trustees of the
 *                    Leland Stanford Junior University.
 *                           All rights reserved.
 *
 *  @endverbatim
 *
 *  @par Facility:
 *  pdd
 *
 *  @author
 *  <russell@slac.stanford.edu>
 *
 *  @par Date created:
 *  <2017/10/07>
 *
 * @par Credits:
 * SLAC
 *
 * This layout the format and primitive access methods to the data
 * found in a TpcFragment.
 *
\* ---------------------------------------------------------------------- */



/* ---------------------------------------------------------------------- *\
   
   HISTORY
   -------
  
   DATE       WHO WHAT
   ---------- --- -------------------------------------------------------
   2017.10.07 jjr Created from TpcFragmentUnpack.hh
  
\* ---------------------------------------------------------------------- */


#include <dam/access/TpcStream.hh>
#include <cstdint>

/* ====================================================================== */
/* FORWARD REFERENCES                                                     */
/* ---------------------------------------------------------------------- */
namespace pdd      {
namespace access   {
class DataFragment;
}
}
/* ---------------------------------------------------------------------- */
/* FORWARD REFERENCES                                                     */
/* ====================================================================== */




/* ====================================================================== */
/* CLASS DEFINITIONS                                                      */
/* ---------------------------------------------------------------------- */
namespace pdd      {
namespace access   {
/* ---------------------------------------------------------------------- */
/* CLASS: TpcFragment                                                     */
/* ---------------------------------------------------------------------- *//*!

  \class TpcFragment
  \brief Access the records within a Tpc Fragment

  \par
   A TpcFragment is a specific example of a generic DataFragment. One
   must verify that the type of the DataFragment from which this class
   is constructed is a TpcFragment by checking its type within the header.
   Once verified, the DataFragment can be used to construct the 
   TpcFragment.
                                                                          */
/* ---------------------------------------------------------------------- */
class TpcFragment
{
public:  
   static const int MaxTpcStreams = 2;

public:
   TpcFragment (pdd::access::DataFragment const &fragment);

public:
   void                          print       ()            const; 
   int                           getNStreams ()            const;
   pdd::access::TpcStream const *getStream   (int istream) const;


private:
   pdd::access::DataFragment  const             &m_df;
   int                                     m_nstreams;
   pdd::access::TpcStream m_tpcStreams[MaxTpcStreams];
};
/* ---------------------------------------------------------------------- */
/* CLASS: TpcFragment                                                     */
/* ---------------------------------------------------------------------- */
} /* END: namespace access                                                */
/* ---------------------------------------------------------------------- */
} /* END: namespace pdd                                                   */
/* ====================================================================== */

#endif 
