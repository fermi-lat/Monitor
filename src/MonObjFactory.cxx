// This class creates the objects that get the input values out of the digi/reco trees.
// Martin Kocian, SLAC, 2/1/07
// Code written for GLAST
//
// Last updated with object timestamp by user kocian on Tue Feb 27 23:48:45 2007
// Last updated with object acdLowerTileCount by user kocian on Tue Mar  6 21:10:00 2007
// Last updated with object eventid by user kocian on Tue Mar  6 22:51:00 2007
// Last updated with object Gem_elapsed by user kocian on Fri Mar  9 19:50:55 2007
// Last updated with object calxtalene by user kocian on Fri Mar  9 20:38:36 2007
// Last updated with object condsummary by user kocian on Fri Mar  9 22:53:38 2007
// Last updated with object configkey1852 by user kocian on Fri Mar 30 18:25:24 2007
// Last updated with object TkrTriggerCounter by user dpaneque on Fri Apr  6 01:33:49 2007
// Last updated with object TkrTriggerTower by user dpaneque on Fri Apr  6 01:40:01 2007
// Last updated with object TkrHitsTowerPlane by user dpaneque on Fri Apr  6 01:40:59 2007
// Last updated with object ToT_Counter by user dpaneque on Fri Apr  6 01:42:22 2007
// Last updated with object ToT_0_Counter by user dpaneque on Fri Apr  6 01:42:54 2007
// Last updated with object ToT_250 by user dpaneque on Fri Apr  6 01:43:25 2007
// Last updated with object ToT_M250 by user dpaneque on Fri Apr  6 01:44:13 2007
// Last updated with object IsTkrDigi by user dpaneque on Fri Apr 13 18:40:42 2007
// Last updated with object ToT_con0 by user dpaneque on Fri Apr 13 18:42:53 2007
// Last updated with object ToT_con1 by user dpaneque on Fri Apr 13 18:44:21 2007
// Last updated with object CalEnergyRaw by user dpaneque on Wed Apr 18 18:28:31 2007
// Last updated with object LivetimeLast by user dpaneque on Fri Apr 27 01:39:12 2007
// Last updated with object DeadZoneLast by user dpaneque on Fri Apr 27 01:42:06 2007
// Last updated with object DiscardedLast by user dpaneque on Fri Apr 27 01:43:54 2007
// Last updated with object PrescaledLast by user dpaneque on Fri Apr 27 01:45:05 2007
// Last updated with object ElapsedLast by user dpaneque on Fri Apr 27 01:46:29 2007
// Last updated with object digitimestamp by user kocian on Fri Apr 20 18:17:48 2007
// Last updated with object filterstatus_hi by user kocian on Fri Apr 20 19:52:10 2007
// Last updated with object CalLoTriggerTower by user kocian on Fri Apr 20 20:12:05 2007
// Last updated with object CalHiTriggerTower by user kocian on Fri Apr 20 20:14:22 2007
// Last updated with object tkrnumtracks by user kocian on Fri Apr 20 20:44:19 2007
// Last updated with object tkr1theta by user kocian on Fri Apr 20 20:46:04 2007
// Last updated with object tkr1hits by user kocian on Fri Apr 20 20:46:47 2007
// Last updated with object calxtalmaxene by user kocian on Fri Apr 20 20:47:47 2007
// Last updated with object gltgemsummary by user kocian on Fri Apr 20 22:06:31 2007
// Last updated with object glttower by user kocian on Fri Apr 20 23:26:52 2007
// Last updated with object gltnumtowers by user kocian on Fri Apr 20 23:27:36 2007
// Last updated with object evtelapsedtime by user kocian on Fri Apr 20 23:38:22 2007
// Last updated with object calxtalmaxtower by user kocian on Fri Apr 20 23:42:44 2007
// Last updated with object Mfilterstatus_hi by user kocian on Sat Apr 21 00:03:41 2007
// Last updated with object ntkrdigis by user kocian on Mon Apr 23 17:13:41 2007
// Last updated with object HFC by user kocian on Mon May 14 20:21:34 2007
// Last updated with object acdpha by user kocian on Sat May 26 18:13:04 2007
// Last updated with object numvetotiles by user kocian on Mon May 28 00:10:38 2007
// Last updated with object AcdGemVeto_AcdTile by user dpaneque on Mon Jun  4 22:34:02 2007
// Last updated with object AcdGemROI_Tower by user dpaneque on Mon Jun  4 22:59:56 2007
// Last updated with object AcdGemCNO_GARC by user dpaneque on Mon Jun  4 23:09:49 2007
// Last updated with object CalXHit_TowerCalLayerCalColumn by user dpaneque on Mon Jun  4 23:37:34 2007
// Last updated with object AcdHit_AcdTile by user dpaneque on Tue Jun  5 00:25:53 2007
// Last updated with object AcdPmtA_OverThreshold_AcdTile by user dpaneque on Tue Jun  5 00:41:02 2007
// Last updated with object AcdPmtB_OverThreshold_AcdTile by user dpaneque on Tue Jun  5 00:42:05 2007
// Last updated with object AcdVetoA_AcdTile by user dpaneque on Tue Jun  5 00:43:35 2007
// Last updated with object AcdVetoB_AcdTile by user dpaneque on Tue Jun  5 00:44:35 2007
// Last updated with object AcdPha_PmtA_AcdTile by user dpaneque on Tue Jun  5 01:11:11 2007
// Last updated with object AcdPha_PmtB_AcdTile by user dpaneque on Tue Jun  5 01:12:23 2007
// Last updated with object callayers by user kocian on Wed May 30 18:47:05 2007
// Last updated with object xoverthresh by user kocian on Thu May 31 20:39:26 2007
// Last updated with object condarrcallo by user kocian on Thu May 31 22:59:44 2007
// Last updated with object condarrcalhi by user kocian on Thu May 31 23:00:27 2007
// Last updated with object mcid by user kocian on Fri Jun  1 21:41:01 2007
// Last updated with object CalXHit_TowerCalLayer by user dpaneque on Thu Jun 28 23:07:31 2007
// Last updated with object ReconNumTracks by user dpaneque on Fri Jun 29 03:03:51 2007
// Last updated with object ReconDirXYZ by user dpaneque on Fri Jun 29 03:05:08 2007
// Last updated with object ReconVertexPosXYZ by user dpaneque on Fri Jun 29 03:06:54 2007
// Last updated with object ReconEnergy_TowerCalLayer by user dpaneque on Fri Jun 29 03:40:27 2007
// Last updated with object condarrtkr by user dpaneque on Sun Jul  1 00:36:38 2007
// Last updated with object condarrcno by user dpaneque on Sun Jul  1 00:37:40 2007
// Last updated with object condarrroi by user dpaneque on Sun Jul  1 00:38:14 2007
// Last updated with object DiscardedDelta by user dpaneque on Sun Jul  1 02:05:05 2007
// Last updated with object DeadZoneDelta by user dpaneque on Sun Jul  1 02:07:07 2007
// Last updated with object timestampdouble by user dpaneque on Fri Jul 20 01:17:49 2007
// Last updated with object ReconEnergy_TowerCalLayerCalColumn by user dpaneque on Sun Jul 22 23:45:43 2007
// Last updated with object ReconEnergy_TowerCalLayerCalColumnCalXFace by user dpaneque on Mon Jul 23 02:25:22 2007
// Last updated with object Tick20MHzDeviation by user dpaneque on Fri Aug 17 19:07:09 2007
// Last updated with object CalXAdc_TowerCalLayerCalColumnFaceRange by user dpaneque on Fri Aug 17 22:14:39 2007
// Last updated with object Range4 by user dpaneque on Tue Aug 21 23:20:51 2007
// Last updated with object CalXtalFaceSignal by user dpaneque on Thu Aug 23 18:28:31 2007
// Last updated with object CalReadoutRange by user dpaneque on Sun Aug 26 17:38:54 2007
// Last updated with object OBFStatus by user dpaneque on Wed Sep 26 01:24:44 2007
// Last updated with object AcdPhaMips_PmtA_AcdTile by user dpaneque on Wed Sep 26 03:52:14 2007
// Last updated with object AcdPhaMips_PmtB_AcdTile by user dpaneque on Wed Sep 26 03:52:50 2007
// Last updated with object Sequence by user dpaneque on Wed Sep 26 22:12:04 2007
// Last updated with object FilterBits by user dpaneque on Thu Sep 27 18:08:37 2007
// Last updated with object PrescaledDelta by user dpaneque on Fri Sep 28 18:41:04 2007
// Last updated with object GltWord by user dpaneque on Sat Sep 29 01:03:08 2007
// Last updated with object CTBBestZDir by user dpaneque on Sat Sep 29 01:06:01 2007
// Last updated with object FT1ZenithTheta by user dpaneque on Sat Sep 29 01:08:22 2007
// Last updated with object CTBClassLevel by user dpaneque on Sat Sep 29 01:10:02 2007
// Last updated with object CTBBestEnergyProb by user dpaneque on Sat Sep 29 01:10:45 2007
// Last updated with object CTBCORE by user dpaneque on Sat Sep 29 01:11:28 2007
// Last updated with object CTBBestEnergy by user dpaneque on Sat Sep 29 01:12:23 2007
// Last updated with object CTBBestEnergyRatio by user dpaneque on Sat Sep 29 01:13:23 2007
// Last updated with object DeltaEventTime by user dpaneque on Wed Oct  3 00:27:24 2007
// Last updated with object DeltaWindowOpen by user dpaneque on Wed Oct  3 00:33:15 2007
// Last updated with object DeltaEventTimeManual by user dpaneque on Mon Oct  8 19:35:18 2007
// Last updated with object TriggerEngine by user dpaneque on Mon Oct  8 20:00:57 2007
// Last updated with object CrateNumber by user dpaneque on Wed Oct 31 01:51:55 2007
// Last updated with object AcdVetoA_OR_B_AcdTile by user dpaneque on Wed Oct 31 19:29:40 2007
// Last updated with object AcdSingleHit by user dpaneque on Wed Oct 31 22:24:42 2007
// Last updated with object AcdSingleVeto_AcdTile by user dpaneque on Wed Oct 31 22:39:07 2007
// Last updated with object DatagramInfo by user dpaneque on Mon Dec 17 21:08:27 2007
// Last updated with object DeltaEvtID by user dpaneque on Tue Dec 18 02:30:41 2007
// Last updated with object Delta_CCSDSTime_EvtTime by user dpaneque on Tue Dec 18 02:35:26 2007
// Last updated with object NewSecond by user dpaneque on Tue Dec 18 04:51:28 2007
// Last updated with object AcdSignalInfo_PMTAcdTilePha by user dpaneque on Sat Jan  5 20:52:15 2008
// Last updated with object AcdHit_PmtGarcGafe by user dpaneque on Sun Jan  6 01:23:23 2008
// Last updated with object AcdVeto_PmtGarcGafe by user dpaneque on Sun Jan  6 01:24:10 2008
// Last updated with object AcdVeto_GafeGarc by user dpaneque on Sun Jan  6 02:11:06 2008
// Last updated with object AcdHit_GafeGarc by user dpaneque on Sun Jan  6 02:11:29 2008
// Last updated with object AcdPhaMipAngleCorrected_PmtExtrapolatedAcdTile by user dpaneque on Sun Jan  6 19:10:52 2008
// Last updated with object AcdPha_PmtIdPmtRangeAcdTile by user dpaneque on Sun Jan  6 22:42:24 2008
// Last updated with object AcdGlobalPos_NotMatchedTrack_FacePosXYZ by user dpaneque on Mon Jan  7 17:34:37 2008
// Last updated with object AcdGlobalPos_ExtrapolatedTrack_MatchedFacePosXYZ by user dpaneque on Mon Jan  7 18:35:28 2008
// Last updated, REMOVING object "MonInput_ReconEnergy_TowerCalLayerCalColumnCalXFace" by user dpaneque on Wed Jan 16 2008 (manual entry)
// Last updated with object ZeroSuppress by user dpaneque on Thu Jan 24 19:13:42 2008
// Last updated with object FastMon_TkrHits by user dpaneque on Tue Feb 26 05:10:44 2008
// Last updated with object fastmontimestampdouble by user dpaneque on Tue Feb 26 05:19:54 2008
// Last updated with object FastMon_TkrHits_TowerPlane by user dpaneque on Tue Feb 26 05:59:16 2008
// Last updated with object FastMon_condsummary by user dpaneque on Tue Feb 26 06:01:21 2008
// Last updated with object FastMon_geomagnetic_InvariantLatitude by user dpaneque on Tue Feb 26 20:48:29 2008
// Last updated with object FastMon_geomagnetic_InvariantLambda by user bregeon on Thu Feb 28 11:08:45 2008
// Last updated with object FastMon_geomagnetic_InvariantRadius by user bregeon on Thu Feb 28 11:19:50 2008
// Last updated with object FastMon_spacecraft_latitude by user bregeon on Thu Feb 28 11:28:10 2008
// Last updated with object FastMon_spacecraft_longitude by user bregeon on Thu Feb 28 11:31:56 2008
// Last updated with object FastMon_spacecraft_altitude by user bregeon on Thu Feb 28 11:34:52 2008
// Last updated with object FastMon_geomagnetic_cutoff by user bregeon on Thu Feb 28 11:38:31 2008
// Last updated with object FastMon_geomagnetic_bb0 by user bregeon on Thu Feb 28 11:40:11 2008
// Last updated with object FastMon_geomagnetic_McIlwainL by user bregeon on Thu Feb 28 11:41:53 2008
// Last updated with object FastMon_Acd_Tile_Count by user bregeon on Thu Feb 28 14:08:11 2008
// Last updated with object FastMon_Cal_Tower_Count by user bregeon on Thu Feb 28 14:18:58 2008
// Last updated with object FastMon_TkrHits_TowerPlaneGTFE by user bregeon on Thu Feb 28 14:49:55 2008
#include "fastmon/MonInput_FastMon_TkrHits_TowerPlaneGTFE.h"
#include "fastmon/MonInput_FastMon_Cal_Tower_Count.h"
#include "fastmon/MonInput_FastMon_Acd_Tile_Count.h"
#include "fastmon/MonInput_FastMon_geomagnetic_McIlwainL.h"
#include "fastmon/MonInput_FastMon_geomagnetic_bb0.h"
#include "fastmon/MonInput_FastMon_geomagnetic_cutoff.h"
#include "fastmon/MonInput_FastMon_spacecraft_altitude.h"
#include "fastmon/MonInput_FastMon_spacecraft_longitude.h"
#include "fastmon/MonInput_FastMon_spacecraft_latitude.h"
#include "fastmon/MonInput_FastMon_geomagnetic_InvariantRadius.h"
#include "fastmon/MonInput_FastMon_geomagnetic_InvariantLambda.h"
#include "fastmon/MonInput_FastMon_geomagnetic_InvariantLatitude.h"
#include "fastmon/MonInput_FastMon_condsummary.h"
#include "fastmon/MonInput_FastMon_TkrHits_TowerPlane.h"
#include "fastmon/MonInput_fastmontimestampdouble.h"
#include "fastmon/MonInput_FastMon_TkrHits.h"
#include "digi/MonInput_ZeroSuppress.h"
#include "recon/MonInput_AcdGlobalPos_ExtrapolatedTrack_MatchedFacePosXYZ.h"
#include "recon/MonInput_AcdGlobalPos_NotMatchedTrack_FacePosXYZ.h"
#include "digi/MonInput_AcdPha_PmtIdPmtRangeAcdTile.h"
#include "recon/MonInput_AcdPhaMipAngleCorrected_PmtExtrapolatedAcdTile.h"
#include "digi/MonInput_AcdHit_GafeGarc.h"
#include "digi/MonInput_AcdVeto_GafeGarc.h"
#include "digi/MonInput_AcdVeto_PmtGarcGafe.h"
#include "digi/MonInput_AcdHit_PmtGarcGafe.h"
#include "digi/MonInput_NewSecond.h"
#include "digi/MonInput_Delta_CCSDSTime_EvtTime.h"
#include "digi/MonInput_DeltaEvtID.h"
#include "digi/MonInput_DatagramInfo.h"
#include "digi/MonInput_AcdSingleVeto_AcdTile.h"
#include "digi/MonInput_AcdSingleHit.h"
#include "digi/MonInput_AcdVetoA_OR_B_AcdTile.h"
#include "digi/MonInput_CrateNumber.h"
#include "digi/MonInput_TriggerEngine.h"
#include "digi/MonInput_DeltaEventTimeManual.h"
#include "digi/MonInput_DeltaWindowOpen.h"
#include "digi/MonInput_DeltaEventTime.h"
#include "merit/MonInput_CTBBestEnergyRatio.h"
#include "merit/MonInput_CTBBestEnergy.h"
#include "merit/MonInput_CTBCORE.h"
#include "merit/MonInput_CTBBestEnergyProb.h"
#include "merit/MonInput_CTBClassLevel.h"
#include "merit/MonInput_FT1ZenithTheta.h"
#include "merit/MonInput_CTBBestZDir.h"
#include "merit/MonInput_GltWord.h"
#include "digi/MonInput_PrescaledDelta.h"
#include "digi/MonInput_FilterBits.h"
#include "digi/MonInput_Sequence.h"
#include "recon/MonInput_AcdPhaMips_PmtB_AcdTile.h"
#include "recon/MonInput_AcdPhaMips_PmtA_AcdTile.h"
#include "digi/MonInput_OBFStatus.h"
#include "digi/MonInput_CalReadoutRange.h"
#include "cal/MonInput_CalXtalFaceSignal.h"
#include "digi/MonInput_Range4.h"
#include "digi/MonInput_CalXAdc_TowerCalLayerCalColumnFaceRange.h"
#include "digi/MonInput_Tick20MHzDeviation.h"
#include "recon/MonInput_ReconEnergy_TowerCalLayerCalColumn.h"
#include "digi/MonInput_timestampdouble.h"
#include "digi/MonInput_DeadZoneDelta.h"
#include "digi/MonInput_DiscardedDelta.h"
#include "digi/MonInput_condarrroi.h"
#include "digi/MonInput_condarrcno.h"
#include "digi/MonInput_condarrtkr.h"
#include "recon/MonInput_ReconEnergy_TowerCalLayer.h"
#include "recon/MonInput_ReconVertexPosXYZ.h"
#include "recon/MonInput_ReconDirXYZ.h"
#include "recon/MonInput_ReconNumTracks.h"
#include "digi/MonInput_CalXHit_TowerCalLayer.h"
#include "digi/MonInput_AcdPha_PmtB_AcdTile.h"
#include "digi/MonInput_AcdPha_PmtA_AcdTile.h"
#include "digi/MonInput_AcdVetoB_AcdTile.h"
#include "digi/MonInput_AcdVetoA_AcdTile.h"
#include "digi/MonInput_AcdPmtB_OverThreshold_AcdTile.h"
#include "digi/MonInput_AcdPmtA_OverThreshold_AcdTile.h"
#include "digi/MonInput_AcdHit_AcdTile.h"
#include "digi/MonInput_CalXHit_TowerCalLayerCalColumn.h"
#include "digi/MonInput_AcdGemCNO_GARC.h"
#include "digi/MonInput_AcdGemROI_Tower.h"
#include "digi/MonInput_AcdGemVeto_AcdTile.h"
#include "merit/MonInput_mcid.h"
#include "digi/MonInput_condarrcalhi.h"
#include "digi/MonInput_condarrcallo.h"
#include "recon/MonInput_xoverthresh.h"
#include "merit/MonInput_callayers.h"
#include "digi/MonInput_ElapsedLast.h"
#include "digi/MonInput_PrescaledLast.h"
#include "digi/MonInput_DiscardedLast.h"
#include "digi/MonInput_DeadZoneLast.h"
#include "digi/MonInput_LivetimeLast.h"
#include "merit/MonInput_CalEnergyRaw.h"
#include "digi/MonInput_numvetotiles.h"
#include "digi/MonInput_acdpha.h"
#include "recon/MonInput_HFC.h"
#include "digi/MonInput_ntkrdigis.h"
#include "merit/MonInput_Mfilterstatus_hi.h"
#include "recon/MonInput_calxtalmaxtower.h"
#include "merit/MonInput_evtelapsedtime.h"
#include "merit/MonInput_gltnumtowers.h"
#include "merit/MonInput_glttower.h"
#include "merit/MonInput_gltgemsummary.h"
#include "merit/MonInput_calxtalmaxene.h"
#include "merit/MonInput_tkr1hits.h"
#include "merit/MonInput_tkr1theta.h"
#include "merit/MonInput_tkrnumtracks.h"
#include "digi/MonInput_CalHiTriggerTower.h"
#include "digi/MonInput_CalLoTriggerTower.h"
#include "digi/MonInput_filterstatus_hi.h"
#include "digi/MonInput_digitimestamp.h"
#include "digi/MonInput_ToT_con1_TowerPlane.h"
#include "digi/MonInput_ToT_con0_TowerPlane.h"
#include "digi/MonInput_IsTkrDigi_TowerPlane.h"
#include "digi/MonInput_TkrHitsTowerPlane.h"
#include "digi/MonInput_TkrTriggerTower.h"
#include "digi/MonInput_configkey1852.h"
#include "digi/MonInput_condsummary.h"
#include "svac/MonInput_calxtalene.h"
#include "digi/MonInput_Gem_elapsed.h"
#include "merit/MonInput_eventid.h"
#include "merit/MonInput_acdLowerTileCount.h"
#include "digi/MonInput_timestamp.h"
#include "digi/MonInput_nAcd.h"
#include "MonObjFactory.h"
#include <iostream>



MonObjFactory::MonObjFactory(){;}
MonInputObject* MonObjFactory::getMonInputObject(string s){
  if(s=="nACD")
    return new MonInput_nAcd;
  if (s=="timestamp")
    return new MonInput_timestamp;
  if (s=="acdLowerTileCount")
    return new MonInput_acdLowerTileCount;
  if (s=="eventid")
    return new MonInput_eventid;
  if (s=="Gem_elapsed")
    return new MonInput_Gem_elapsed;
  if (s=="calxtalene")
    return new MonInput_calxtalene;
  if (s=="condsummary")
    return new MonInput_condsummary;
  if (s=="configkey1852")
    return new MonInput_configkey1852;

  if (s=="TkrTriggerTower")
    return new MonInput_TkrTriggerTower;
  if (s=="TkrHitsTowerPlane")
    return new MonInput_TkrHitsTowerPlane;
  if (s=="IsTkrDigi_TowerPlane")
    return new MonInput_IsTkrDigi_TowerPlane;
  if (s=="ToT_con0_TowerPlane")
    return new MonInput_ToT_con0_TowerPlane;
  if (s=="ToT_con1_TowerPlane")
    return new MonInput_ToT_con1_TowerPlane;
  if (s=="CalEnergyRaw")
    return new MonInput_CalEnergyRaw;
  if (s=="LivetimeLast")
    return new MonInput_LivetimeLast;
  if (s=="DeadZoneLast")
    return new MonInput_DeadZoneLast;
  if (s=="DiscardedLast")
    return new MonInput_DiscardedLast;
  if (s=="PrescaledLast")
    return new MonInput_PrescaledLast;
  if (s=="ElapsedLast")
    return new MonInput_ElapsedLast;
  if (s=="digitimestamp")
    return new MonInput_digitimestamp;
  if (s=="filterstatus_hi")
    return new MonInput_filterstatus_hi;
  if (s=="CalLoTriggerTower")
    return new MonInput_CalLoTriggerTower;
  if (s=="CalHiTriggerTower")
    return new MonInput_CalHiTriggerTower;
  if (s=="tkrnumtracks")
    return new MonInput_tkrnumtracks;
  if (s=="tkr1theta")
    return new MonInput_tkr1theta;
  if (s=="tkr1hits")
    return new MonInput_tkr1hits;
  if (s=="calxtalmaxene")
    return new MonInput_calxtalmaxene;
  if (s=="gltgemsummary")
    return new MonInput_gltgemsummary;
  if (s=="glttower")
    return new MonInput_glttower;
  if (s=="gltnumtowers")
    return new MonInput_gltnumtowers;
  if (s=="evtelapsedtime")
    return new MonInput_evtelapsedtime;
  if (s=="calxtalmaxtower")
    return new MonInput_calxtalmaxtower;
  if (s=="Mfilterstatus_hi")
    return new MonInput_Mfilterstatus_hi;
  if (s=="ntkrdigis")
    return new MonInput_ntkrdigis;
  if (s=="HFC")
    return new MonInput_HFC;
  if (s=="acdpha")
    return new MonInput_acdpha;
  if (s=="numvetotiles")
    return new MonInput_numvetotiles;
  if (s=="AcdGemVeto_AcdTile")
    return new MonInput_AcdGemVeto_AcdTile;
  if (s=="AcdGemROI_Tower")
    return new MonInput_AcdGemROI_Tower;
  if (s=="AcdGemCNO_GARC")
    return new MonInput_AcdGemCNO_GARC;
  if (s=="CalXHit_TowerCalLayerCalColumn")
    return new MonInput_CalXHit_TowerCalLayerCalColumn;
  if (s=="AcdHit_AcdTile")
    return new MonInput_AcdHit_AcdTile;
  if (s=="AcdPmtA_OverThreshold_AcdTile")
    return new MonInput_AcdPmtA_OverThreshold_AcdTile;
  if (s=="AcdPmtB_OverThreshold_AcdTile")
    return new MonInput_AcdPmtB_OverThreshold_AcdTile;
  if (s=="AcdVetoA_AcdTile")
    return new MonInput_AcdVetoA_AcdTile;
  if (s=="AcdVetoB_AcdTile")
    return new MonInput_AcdVetoB_AcdTile;
  if (s=="AcdPha_PmtA_AcdTile")
    return new MonInput_AcdPha_PmtA_AcdTile;
  if (s=="AcdPha_PmtB_AcdTile")
    return new MonInput_AcdPha_PmtB_AcdTile;
  if (s=="callayers")
    return new MonInput_callayers;
  if (s=="xoverthresh")
    return new MonInput_xoverthresh;
  if (s=="condarrcallo")
    return new MonInput_condarrcallo;
  if (s=="condarrcalhi")
    return new MonInput_condarrcalhi;
  if (s=="mcid")
    return new MonInput_mcid;
  if (s=="CalXHit_TowerCalLayer")
    return new MonInput_CalXHit_TowerCalLayer;
  if (s=="ReconNumTracks")
    return new MonInput_ReconNumTracks;
  if (s=="ReconDirXYZ")
    return new MonInput_ReconDirXYZ;
  if (s=="ReconVertexPosXYZ")
    return new MonInput_ReconVertexPosXYZ;
  if (s=="ReconEnergy_TowerCalLayer")
    return new MonInput_ReconEnergy_TowerCalLayer;
  if (s=="condarrtkr")
    return new MonInput_condarrtkr;
  if (s=="condarrcno")
    return new MonInput_condarrcno;
  if (s=="condarrroi")
    return new MonInput_condarrroi;
  if (s=="DiscardedDelta")
    return new MonInput_DiscardedDelta;
  if (s=="DeadZoneDelta")
    return new MonInput_DeadZoneDelta;
  if (s=="timestampdouble")
    return new MonInput_timestampdouble;
  if (s=="ReconEnergy_TowerCalLayerCalColumn")
    return new MonInput_ReconEnergy_TowerCalLayerCalColumn;
  if (s=="Tick20MHzDeviation")
    return new MonInput_Tick20MHzDeviation;
  if (s=="CalXAdc_TowerCalLayerCalColumnFaceRange")
    return new MonInput_CalXAdc_TowerCalLayerCalColumnFaceRange;
  if (s=="Range4")
    return new MonInput_Range4;
  if (s=="CalXtalFaceSignal")
    return new MonInput_CalXtalFaceSignal;
  if (s=="CalReadoutRange")
    return new MonInput_CalReadoutRange;
  if (s=="OBFStatus")
    return new MonInput_OBFStatus;
  if (s=="AcdPhaMips_PmtA_AcdTile")
    return new MonInput_AcdPhaMips_PmtA_AcdTile;
  if (s=="AcdPhaMips_PmtB_AcdTile")
    return new MonInput_AcdPhaMips_PmtB_AcdTile;
  if (s=="Sequence")
    return new MonInput_Sequence;
  if (s=="FilterBits")
    return new MonInput_FilterBits;
  if (s=="PrescaledDelta")
    return new MonInput_PrescaledDelta;
  if (s=="GltWord")
    return new MonInput_GltWord;
  if (s=="CTBBestZDir")
    return new MonInput_CTBBestZDir;
  if (s=="FT1ZenithTheta")
    return new MonInput_FT1ZenithTheta;
  if (s=="CTBClassLevel")
    return new MonInput_CTBClassLevel;
  if (s=="CTBBestEnergyProb")
    return new MonInput_CTBBestEnergyProb;
  if (s=="CTBCORE")
    return new MonInput_CTBCORE;
  if (s=="CTBBestEnergy")
    return new MonInput_CTBBestEnergy;
  if (s=="CTBBestEnergyRatio")
    return new MonInput_CTBBestEnergyRatio;
  if (s=="DeltaEventTime")
    return new MonInput_DeltaEventTime;
  if (s=="DeltaWindowOpen")
    return new MonInput_DeltaWindowOpen;
  if (s=="DeltaEventTimeManual")
    return new MonInput_DeltaEventTimeManual;
  if (s=="TriggerEngine")
    return new MonInput_TriggerEngine;
  if (s=="CrateNumber")
    return new MonInput_CrateNumber;
  if (s=="AcdVetoA_OR_B_AcdTile")
    return new MonInput_AcdVetoA_OR_B_AcdTile;
  if (s=="AcdSingleHit")
    return new MonInput_AcdSingleHit;
  if (s=="AcdSingleVeto_AcdTile")
    return new MonInput_AcdSingleVeto_AcdTile;
  if (s=="DatagramInfo")
    return new MonInput_DatagramInfo;
  if (s=="DeltaEvtID")
    return new MonInput_DeltaEvtID;
  if (s=="Delta_CCSDSTime_EvtTime")
    return new MonInput_Delta_CCSDSTime_EvtTime;
  if (s=="NewSecond")
    return new MonInput_NewSecond;
  if (s=="AcdHit_PmtGarcGafe")
    return new MonInput_AcdHit_PmtGarcGafe;
  if (s=="AcdVeto_PmtGarcGafe")
    return new MonInput_AcdVeto_PmtGarcGafe;
  if (s=="AcdVeto_GafeGarc")
    return new MonInput_AcdVeto_GafeGarc;
  if (s=="AcdHit_GafeGarc")
    return new MonInput_AcdHit_GafeGarc;
  if (s=="AcdPhaMipAngleCorrected_PmtExtrapolatedAcdTile")
    return new MonInput_AcdPhaMipAngleCorrected_PmtExtrapolatedAcdTile;
  if (s=="AcdPha_PmtIdPmtRangeAcdTile")
    return new MonInput_AcdPha_PmtIdPmtRangeAcdTile;
  if (s=="AcdGlobalPos_NotMatchedTrack_FacePosXYZ")
    return new MonInput_AcdGlobalPos_NotMatchedTrack_FacePosXYZ;
  if (s=="AcdGlobalPos_ExtrapolatedTrack_MatchedFacePosXYZ")
    return new MonInput_AcdGlobalPos_ExtrapolatedTrack_MatchedFacePosXYZ;
  if (s=="ZeroSuppress")
    return new MonInput_ZeroSuppress;
  if (s=="FastMon_TkrHits")
    return new MonInput_FastMon_TkrHits;
  if (s=="fastmontimestampdouble")
    return new MonInput_fastmontimestampdouble;
  if (s=="FastMon_TkrHits_TowerPlane")
    return new MonInput_FastMon_TkrHits_TowerPlane;
  if (s=="FastMon_condsummary")
    return new MonInput_FastMon_condsummary;
  if (s=="FastMon_geomagnetic_InvariantLatitude")
    return new MonInput_FastMon_geomagnetic_InvariantLatitude;
  if (s=="FastMon_geomagnetic_InvariantLambda")
    return new MonInput_FastMon_geomagnetic_InvariantLambda;
  if (s=="FastMon_geomagnetic_InvariantRadius")
    return new MonInput_FastMon_geomagnetic_InvariantRadius;
  if (s=="FastMon_spacecraft_latitude")
    return new MonInput_FastMon_spacecraft_latitude;
  if (s=="FastMon_spacecraft_longitude")
    return new MonInput_FastMon_spacecraft_longitude;
  if (s=="FastMon_spacecraft_altitude")
    return new MonInput_FastMon_spacecraft_altitude;
  if (s=="FastMon_geomagnetic_cutoff")
    return new MonInput_FastMon_geomagnetic_cutoff;
  if (s=="FastMon_geomagnetic_bb0")
    return new MonInput_FastMon_geomagnetic_bb0;
  if (s=="FastMon_geomagnetic_McIlwainL")
    return new MonInput_FastMon_geomagnetic_McIlwainL;
  if (s=="FastMon_Acd_Tile_Count")
    return new MonInput_FastMon_Acd_Tile_Count;
  if (s=="FastMon_Cal_Tower_Count")
    return new MonInput_FastMon_Cal_Tower_Count;
  if (s=="FastMon_TkrHits_TowerPlaneGTFE")
    return new MonInput_FastMon_TkrHits_TowerPlaneGTFE;
  // This line is a tag for makeNewMonObject.pl. Do not move or remove.
  else{
    std::cout<<"Object "<<s<<" does not exist"<<std::endl;
    assert(0);
  }
}

const std::map<std::string, std::map<std::string, std::string> > MonObjFactory::getDescriptions(){
  std::map<std::string, std::map<std::string, std::string> > descriptions;
  std::vector<std::string> names;
  names.push_back("nACD");
  names.push_back("timestamp");
  names.push_back("acdLowerTileCount");
  names.push_back("eventid");
  names.push_back("Gem_elapsed");
  names.push_back("calxtalene");
  names.push_back("condsummary");
  names.push_back("configkey1852");
  //names.push_back("onedimbool");
  //names.push_back("twodimbool");
  //names.push_back("onedimshort");
  //names.push_back("twodimshort");
  names.push_back("TkrTriggerTower");
  names.push_back("TkrHitsTowerPlane");
  names.push_back("IsTkrDigi_TowerPlane");
  names.push_back("ToT_con0_TowerPlane");
  names.push_back("ToT_con1_TowerPlane");
  names.push_back("digitimestamp");
  names.push_back("filterstatus_hi");
  names.push_back("CalLoTriggerTower");
  names.push_back("CalHiTriggerTower");
  names.push_back("tkrnumtracks");
  names.push_back("tkr1theta");
  names.push_back("tkr1hits");
  names.push_back("calxtalmaxene");
  names.push_back("gltgemsummary");
  names.push_back("glttower");
  names.push_back("gltnumtowers");
  names.push_back("evtelapsedtime");
  names.push_back("calxtalmaxtower");
  names.push_back("Mfilterstatus_hi");
  names.push_back("ntkrdigis");
  names.push_back("HFC");
  names.push_back("acdpha");
  names.push_back("numvetotiles");
  names.push_back("AcdGemVeto_AcdTile");
  names.push_back("AcdGemROI_Tower");
  names.push_back("AcdGemCNO_GARC");
  names.push_back("CalXHit_TowerCalLayerCalColumn");
  names.push_back("AcdHit_AcdTile");
  names.push_back("AcdPmtA_OverThreshold_AcdTile");
  names.push_back("AcdPmtB_OverThreshold_AcdTile");
  names.push_back("AcdVetoA_AcdTile");
  names.push_back("AcdVetoB_AcdTile");
  names.push_back("AcdPha_PmtA_AcdTile");
  names.push_back("AcdPha_PmtB_AcdTile");
  names.push_back("callayers");
  names.push_back("xoverthresh");
  names.push_back("condarrcallo");
  names.push_back("condarrcalhi");
  names.push_back("mcid");
  names.push_back("CalXHit_TowerCalLayer");
  names.push_back("ReconNumTracks");
  names.push_back("ReconDirXYZ");
  names.push_back("ReconVertexPosXYZ");
  names.push_back("ReconEnergy_TowerCalLayer");
  names.push_back("condarrtkr");
  names.push_back("condarrcno");
  names.push_back("condarrroi");
  names.push_back("GemDiscardedDelta");
  names.push_back("DeadZoneDelta");
  names.push_back("timestampdouble");
  names.push_back("ReconEnergy_TowerCalLayerCalColumn");
  names.push_back("Tick20MHzDeviation");
  names.push_back("CalXAdc_TowerCalLayerCalColumnFaceRange");
  names.push_back("Range4");
  names.push_back("CalXtalFaceSignal");
  names.push_back("CalReadoutRange");
  names.push_back("OBFStatus");
  names.push_back("AcdPhaMips_PmtA_AcdTile");
  names.push_back("AcdPhaMips_PmtB_AcdTile");
  names.push_back("Sequence");
  names.push_back("FilterBits");
  names.push_back("PrescaledDelta");
  names.push_back("GltWord");
  names.push_back("CTBBestZDir");
  names.push_back("FT1ZenithTheta");
  names.push_back("CTBClassLevel");
  names.push_back("CTBBestEnergyProb");
  names.push_back("CTBCORE");
  names.push_back("CTBBestEnergy");
  names.push_back("CTBBestEnergyRatio");
  names.push_back("DeltaEventTime");
  names.push_back("DeltaWindowOpen");
  names.push_back("DeltaEventTimeManual");
  names.push_back("TriggerEngine");
  names.push_back("CrateNumber");
  names.push_back("AcdVetoA_OR_B_AcdTile");
  names.push_back("AcdSingleHit");
  names.push_back("AcdSingleVeto_AcdTile");
  names.push_back("DatagramInfo");
  names.push_back("DeltaEvtID");
  names.push_back("Delta_CCSDSTime_EvtTime");
  names.push_back("NewSecond");
  names.push_back("AcdSignalInfo_PMTAcdTilePha");
  names.push_back("AcdHit_PmtGarcGafe");
  names.push_back("AcdVeto_PmtGarcGafe");
  names.push_back("AcdVeto_GafeGarc");
  names.push_back("AcdHit_GafeGarc");
  names.push_back("AcdPhaMipAngleCorrected_PmtExtrapolatedAcdTile");
  names.push_back("AcdPha_PmtIdPmtRangeAcdTile");
  names.push_back("AcdGlobalPos_NotMatchedTrack_FacePosXYZ");
  names.push_back("AcdGlobalPos_ExtrapolatedTrack_MatchedFacePosXYZ");
  names.push_back("ZeroSuppress");
  names.push_back("FastMon_TkrHits");
  names.push_back("fastmontimestampdouble");
  names.push_back("FastMon_TkrHits_TowerPlane");
  names.push_back("FastMon_condsummary");
  names.push_back("FastMon_geomagnetic_InvariantLatitude");
  names.push_back("FastMon_geomagnetic_InvariantLambda");
  names.push_back("FastMon_geomagnetic_InvariantRadius");
  names.push_back("FastMon_spacecraft_latitude");
  names.push_back("FastMon_spacecraft_longitude");
  names.push_back("FastMon_spacecraft_altitude");
  names.push_back("FastMon_geomagnetic_cutoff");
  names.push_back("FastMon_geomagnetic_bb0");
  names.push_back("FastMon_geomagnetic_McIlwainL");
  names.push_back("FastMon_Acd_Tile_Count");
  names.push_back("FastMon_Cal_Tower_Count");
  names.push_back("FastMon_TkrHits_TowerPlaneGTFE");
  // another tag used by makeNewMonObject.pl. Do not move or remove.
  for (unsigned int i=0;i<names.size();i++){
    MonInputObject* obj=getMonInputObject(names[i]);
    descriptions[names[i]]["Description"]=obj->getDescription();
    descriptions[names[i]]["Source"]=obj->getInputSource();
    delete obj;
  }
  return descriptions;
}
