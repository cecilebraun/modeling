/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config S:/SDVAL_RAMS/F�rderprojekte/openETCS/modeling/model/Scade/System/ObuFunctions/ManageLocationRelatedInformation/MLRI_Integration/KCG\kcg_s2c_config.txt
** Generation date: 2014-12-12T12:03:54
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "MLRI__odoLoc_2_refLocations_BasicLocationFunctions_Pkg.h"

/** Determines the location of an element, measured by odometry, with reference to 2 different known reference locations. */
/** The location of the element can, but must not be necessarily between the two reference locations. */
/** If the locations, calculated internally from refLoc2 and refLoc1 don't overlap, the resulting location will be selected from refLoc1 alone. */
/** This function can be used to calculate the location of an unlinked balise group between 2 linked balise groups. */
/** "Remark_1" {Description = "Determines the location of an element, measured by odometry, with reference to 2 different known reference locations - Copyright Siemens AG, 2014 - Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl ) - Gist URL: --- - Cryptography: No - Author(s): Uwe Steinke   The use of this software is limited to non-vital applications.  It has not been developed for vital operation purposes and must not be used for applications which may cause harm to people, physical accidents or financial loss.  THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.  "} */
/** "GdC_1" {Author = "Uwe Steinke", DateC = "Created : 2014-05-22", DateM = "Modified : 2014-05-22", Version = "00.02.00"} */
/* BasicLocationFunctions_Pkg::odoLoc_2_refLocations */
void MLRI__odoLoc_2_refLocations_BasicLocationFunctions_Pkg(
  /* BasicLocationFunctions_Pkg::odoLoc_2_refLocations::refLoc_2 */MLRI__LocWithInAcc_T_Obu_BasicTypes_Pkg *refLoc_2,
  /* BasicLocationFunctions_Pkg::odoLoc_2_refLocations::refLoc_1 */MLRI__LocWithInAcc_T_Obu_BasicTypes_Pkg *refLoc_1,
  /* BasicLocationFunctions_Pkg::odoLoc_2_refLocations::refOdo_2 */MLRI__OdometryLocations_T_Obu_BasicTypes_Pkg *refOdo_2,
  /* BasicLocationFunctions_Pkg::odoLoc_2_refLocations::refOdo_1 */MLRI__OdometryLocations_T_Obu_BasicTypes_Pkg *refOdo_1,
  /* BasicLocationFunctions_Pkg::odoLoc_2_refLocations::odo */MLRI__OdometryLocations_T_Obu_BasicTypes_Pkg *odo,
  /* BasicLocationFunctions_Pkg::odoLoc_2_refLocations::location */MLRI__LocWithInAcc_T_Obu_BasicTypes_Pkg *location)
{
  MLRI__LocWithInAcc_T_Obu_BasicTypes_Pkg tmp;
  /* BasicLocationFunctions_Pkg::odoLoc_2_refLocations::_L1 */ MLRI__LocWithInAcc_T_Obu_BasicTypes_Pkg _L1;
  /* BasicLocationFunctions_Pkg::odoLoc_2_refLocations::_L11 */ kcg_bool _L11;
  /* BasicLocationFunctions_Pkg::odoLoc_2_refLocations::_L10 */ MLRI__LocWithInAcc_T_Obu_BasicTypes_Pkg _L10;
  
  /* 1 */
  MLRI__add_odo_2_Location_BasicLocationFunctions_Pkg(
    refLoc_1,
    refOdo_1,
    odo,
    &_L1);
  /* 2 */
  MLRI__add_odo_2_Location_BasicLocationFunctions_Pkg(
    refLoc_2,
    refOdo_2,
    odo,
    &tmp);
  /* 1 */
  MLRI__overlapOf_2_Locations_BasicLocationFunctions_Pkg(
    &tmp,
    &_L1,
    &_L10,
    &_L11);
  if (_L11) {
    MLRI__kcg_copy_LocWithInAcc_T_Obu_BasicTypes_Pkg(location, &_L10);
  }
  else {
    MLRI__kcg_copy_LocWithInAcc_T_Obu_BasicTypes_Pkg(location, &_L1);
  }
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** MLRI__odoLoc_2_refLocations_BasicLocationFunctions_Pkg.c
** Generation date: 2014-12-12T12:03:54
*************************************************************$ */
