// adapted from Geant4 example

#ifndef FaserDetectorConstruction_h
#define FaserDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4RotationMatrix.hh"
#include "G4Cache.hh"
#include "G4SystemOfUnits.hh"
#include "globals.hh"


class FaserGeometryMessenger;
class FaserFieldSetup;
class G4VPhysicalVolume;
class G4LogicalVolume;

/// Detector construction class to define materials and geometry.

class FaserDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
  FaserDetectorConstruction();
  virtual ~FaserDetectorConstruction();

  virtual G4VPhysicalVolume* Construct();
  virtual void ConstructSDandField();
    
  virtual void setReadoutStrips(G4int value) { sensor_readoutStrips = value; }
  virtual G4int getReadoutStrips() const { return sensor_readoutStrips; }

  virtual void setStripPitch(G4double value) { sensor_stripPitch = value; }
  virtual G4double getStripPitch() const { return sensor_stripPitch; }

  virtual void setStripLength(G4double value) { sensor_stripLength = value; }
  virtual G4double getStripLength() const { return sensor_stripLength; }

  virtual void setSensorGap(G4double value) { sensor_gap = value; }
  virtual G4double getSensorGap() const { return sensor_gap; }

  virtual void setSensorSizeZ(G4double value) { sensor_sizeZ = value; }
  virtual G4double getSensorSizeZ() const { return sensor_sizeZ; }

  virtual void setSensorStereoAngle(G4double value) { sensor_stereoAngle = value; }
  virtual G4double getSensorStereoAngle() const { return sensor_stereoAngle; }

  virtual void setSupportSizeZ(G4double value) { support_sizeZ = value; }
  virtual G4double getSupportSizeZ() const { return support_sizeZ; }

  virtual void setSensorPlanes(G4int value) { detector_sensorPlanes = value; }
  virtual G4int getSensorPlanes() const { return detector_sensorPlanes; }

  virtual void setPlanePitch(G4double value) { detector_planePitch = value; }
  virtual G4double getPlanePitch() const { return detector_planePitch; }

  virtual void setDecayVolumeLength(G4double value) { detector_decayVolumeLength = value; }
  virtual G4double getDecayVolumeLength() const { return detector_decayVolumeLength; }


  static constexpr G4double default_sensor_activeSizeY = 96.669*mm;

  static constexpr G4int    default_sensor_readoutStrips = 1280;
  static constexpr G4double default_sensor_stripPitch = 75.5*um;
  static constexpr G4double default_sensor_stripLength = 48.20*mm;
  static constexpr G4double default_sensor_gap = default_sensor_activeSizeY - 2 * default_sensor_stripLength;
  static constexpr G4double default_sensor_sizeZ = 0.32*mm;
  static constexpr G4double default_sensor_stereoAngle = 26.0*mrad;
  static constexpr G4double default_support_sizeZ = 3.3*mm;
  static constexpr G4int    default_detector_sensorPlanes = 5;
  static constexpr G4double default_detector_planePitch = 1.0*m;
  static constexpr G4double default_detector_decayVolumeLength = 5.0*m;

  protected:

  FaserGeometryMessenger* fGeometryMessenger;
  G4LogicalVolume* fLogicTracker;

  // tunable (from macro) parameters 
  G4int    sensor_readoutStrips;
  G4double sensor_stripPitch;
  G4double sensor_stripLength;
  G4double sensor_gap;
  G4double sensor_sizeZ;
  G4double sensor_stereoAngle;
  G4double support_sizeZ;
  G4int    detector_sensorPlanes;
  G4double detector_planePitch;
  G4double detector_decayVolumeLength;

  // these are not copied by the volumes that use them,
  // so they must not be changed

  G4RotationMatrix* fStereoPlus;
  G4RotationMatrix* fStereoMinus;
  G4RotationMatrix* fOverlapAngle;

  // mag field
  G4Cache<FaserFieldSetup*> fFieldSetup;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

