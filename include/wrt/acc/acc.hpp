/**
 * Assetto Corsa Competizione shared memory implementation
 * Version: v1.8.12
 * Webpage: https://www.assettocorsa.net/forum/index.php?threads/acc-shared-memory-documentation.59965/
 *
 * Notes:
 * - Struct members starting with an underscore are not used in Shared Memory.
 * - Arrays with wheel data are always stored as follows:
 *   front left (0), front right (1), rear left (2), rear right (3).
 *   You can use the ACC_FrontLeft, ACC_FrontRight, ACC_RearLeft and
 *   ACC_RearRight to index into those arrays without thinking about these indices.
 * - Certain variable names are slightly changed for more naming consistency. Yup, I really did that.
 */

#ifndef WRT_ACC_ACC_HPP
#define WRT_ACC_ACC_HPP

namespace wrt::acc
{
	typedef int ACC_FLAG_TYPE;
	constexpr ACC_FLAG_TYPE ACC_NO_FLAG = 0;
	constexpr ACC_FLAG_TYPE ACC_BLUE_FLAG = 1;
	constexpr ACC_FLAG_TYPE ACC_YELLOW_FLAG = 2;
	constexpr ACC_FLAG_TYPE ACC_BLACK_FLAG = 3;
	constexpr ACC_FLAG_TYPE ACC_WHITE_FLAG = 4;
	constexpr ACC_FLAG_TYPE ACC_CHECKERED_FLAG = 5;
	constexpr ACC_FLAG_TYPE ACC_PENALTY_FLAG = 6;
	constexpr ACC_FLAG_TYPE ACC_GREEN_FLAG = 7;
	constexpr ACC_FLAG_TYPE ACC_ORANGE_FLAG = 8;

	typedef int ACC_PENALTY_TYPE;
	constexpr ACC_PENALTY_TYPE ACC_None = 0;
	constexpr ACC_PENALTY_TYPE ACC_DriveThrough_Cutting = 1;
	constexpr ACC_PENALTY_TYPE ACC_StopAndGo_10_Cutting = 2;
	constexpr ACC_PENALTY_TYPE ACC_StopAndGo_20_Cutting = 3;
	constexpr ACC_PENALTY_TYPE ACC_StopAndGo_30_Cutting = 4;
	constexpr ACC_PENALTY_TYPE ACC_Disqualified_Cutting = 5;
	constexpr ACC_PENALTY_TYPE ACC_RemoveBestLaptime_Cutting = 6;
	constexpr ACC_PENALTY_TYPE ACC_DriveThrough_PitSpeeding = 7;
	constexpr ACC_PENALTY_TYPE ACC_StopAndGo_10_PitSpeeding = 8;
	constexpr ACC_PENALTY_TYPE ACC_StopAndGo_20_PitSpeeding = 9;
	constexpr ACC_PENALTY_TYPE ACC_StopAndGo_30_PitSpeeding = 10;
	constexpr ACC_PENALTY_TYPE ACC_Disqualified_PitSpeeding = 11;
	constexpr ACC_PENALTY_TYPE ACC_RemoveBestLaptime_PitSpeeding = 12;
	constexpr ACC_PENALTY_TYPE ACC_Disqualified_IgnoredMandatoryPit = 13;
	constexpr ACC_PENALTY_TYPE ACC_PostRaceTime = 14;
	constexpr ACC_PENALTY_TYPE ACC_Disqualified_Trolling = 15;
	constexpr ACC_PENALTY_TYPE ACC_Disqualified_PitEntry = 16;
	constexpr ACC_PENALTY_TYPE ACC_Disqualified_PitExit = 17;
	constexpr ACC_PENALTY_TYPE ACC_Disqualified_WrongWay = 18;
	constexpr ACC_PENALTY_TYPE ACC_DriveThrough_IgnoredDriverStint = 19;
	constexpr ACC_PENALTY_TYPE ACC_Disqualified_IgnoredDriverStint = 20;
	constexpr ACC_PENALTY_TYPE ACC_Disqualified_ExceededDriverStintLimit = 21;

	typedef int ACC_SESSION_TYPE;
	constexpr ACC_SESSION_TYPE ACC_UNKNOWN = -1;
	constexpr ACC_SESSION_TYPE ACC_PRACTICE = 0;
	constexpr ACC_SESSION_TYPE ACC_QUALIFY = 1;
	constexpr ACC_SESSION_TYPE ACC_RACE = 2;
	constexpr ACC_SESSION_TYPE ACC_HOTLAP = 3;
	constexpr ACC_SESSION_TYPE ACC_TIMEATTACK = 4;
	constexpr ACC_SESSION_TYPE ACC_DRIFT = 5;
	constexpr ACC_SESSION_TYPE ACC_DRAG = 6;
	constexpr ACC_SESSION_TYPE ACC_HOTSTINT = 7;
	constexpr ACC_SESSION_TYPE ACC_HOTSTINTSUPERPOLE = 8;

	typedef int ACC_STATUS;
	constexpr ACC_STATUS ACC_OFF = 0;
	constexpr ACC_STATUS ACC_REPLAY = 1;
	constexpr ACC_STATUS ACC_LIVE = 2;
	constexpr ACC_STATUS ACC_PAUSE = 3;

	typedef int ACC_WHEELS_TYPE;
	constexpr ACC_WHEELS_TYPE ACC_FrontLeft = 0;
	constexpr ACC_WHEELS_TYPE ACC_FrontRight = 1;
	constexpr ACC_WHEELS_TYPE ACC_RearLeft = 2;
	constexpr ACC_WHEELS_TYPE ACC_RearRight = 3;

	typedef int ACC_TRACK_GRIP_STATUS;
	constexpr ACC_TRACK_GRIP_STATUS ACC_GREEN = 0;
	constexpr ACC_TRACK_GRIP_STATUS ACC_FAST = 1;
	constexpr ACC_TRACK_GRIP_STATUS ACC_OPTIMUM = 2;
	constexpr ACC_TRACK_GRIP_STATUS ACC_GREASY = 3;
	constexpr ACC_TRACK_GRIP_STATUS ACC_DAMP = 4;
	constexpr ACC_TRACK_GRIP_STATUS ACC_WET = 5;
	constexpr ACC_TRACK_GRIP_STATUS ACC_FLOODED = 6;

	typedef int ACC_RAIN_INTENSITY;
	constexpr ACC_RAIN_INTENSITY ACC_NO_RAIN = 0;
	constexpr ACC_RAIN_INTENSITY ACC_DRIZZLE = 1;
	constexpr ACC_RAIN_INTENSITY ACC_LIGHT_RAIN = 2;
	constexpr ACC_RAIN_INTENSITY ACC_MEDIUM_RAIN = 3;
	constexpr ACC_RAIN_INTENSITY ACC_HEAVY_RAIN = 4;
	constexpr ACC_RAIN_INTENSITY ACC_THUNDERSTORM = 5;

#pragma pack(push)
#pragma pack(4)

	struct SPageFileStatic
	{
		wchar_t smVersion[15];					// Shared memory version
		wchar_t accVersion[15];					// Game version
		int sessions;							// Number of sessions
		int cars;								// Number of cars
		wchar_t carModel[33];					// Player car model
		wchar_t track[33];						// Track name
		wchar_t playerName[33];					// Player name
		wchar_t playerSurname[33];				// Player surname
		wchar_t playerNickname[33];				// Player nickname
		int sectorCount;						// Number of sectors
		float _maxTorque;
		float _maxPower;
		int maxRpm;								// Maximum rpm
		float maxFuel;							// Maximum fuel tank capacity
		float _suspensionMaxTravel[4];
		float _tyreRadius[4];
		float _maxTurboBoost;
		float _deprecated1;
		float _deprecated2;
		int isPenaltiesEnabled;					// Penalties enabled
		float fuelRate;							// Fuel consumption rate
		float tyreWearRate;						// Tyre wear rate
		float mechanicalDamageRate;				// Mechanical damage rate
		int isTyreBlanketsAllowed;				// Not allowed in Bancpain endurance series
		float stability;						// Stability control used
		int isAutoClutch;						// Auto clutch used
		int isAutoBlip;							// Always true
		int _hasDRS;
		int _hasERS;
		int _hasKERS;
		float _kersMaxJ;
		int _engineBrakeSettingsCount;
		int _ersPowerControllerCount;
		float _trackSPlineLength;
		wchar_t _trackConfiguration[33];
		float _ersMaxJ;
		int _isTimedRace;
		int _hasExtraLap;
		wchar_t _carSkin[33];
		int _reversedGridPositions;
		int pitWindowStart;						// Pit window opening time
		int pitWindowEnd;						// Pit window closing time
		int isOnline;							// Is a multiplayer session
		wchar_t dryTyresName[33];				// Name of the dry tyres
		wchar_t wetTyresName[33];				// Name of the wet tyres
	};

	struct SPageFilePhysics
	{
		int packetId;							// Current step index
		float gas;								// Gas pedal input value (0.0 to 1.0)
		float brake;							// Brake pedal input value (0.0 to 1.0)
		float fuel;								// Amount of fuel remaining in kg
		int gear;								// Current gear (reverse (0), neutral (1), first (2), etc.)
		int rpm;								// Engine revolutions per minute
		float steerAngle;						// Steering input value (-1.0 to 1.0)
		float speed;							// Speed in km/h
		float velocity[3];						// Velocity vector in global coordinates
		float accG[3];							// Acceleration vector in global coordinates
		float wheelSlip[4];						// Tyre slip per wheel
		float _wheelLoad[4];
		float wheelPressure[4];					// Tyre pressure per wheel
		float wheelAngularSpeed[4];				// Angular speed in rad/s per wheel
		float _tyreWear[4];
		float _tyreDirtyLevel[4];
		float tyreCoreTemperature[4];			// Tyre rubber core temperature per wheel
		float _camber[4];
		float suspensionTravel[4];				// Suspension travel per wheel
		float _drs;
		float tc;								// Traction control
		float yaw;								// Yaw orientation
		float pitch;							// Pitch orientation
		float roll;								// Roll orientation
		float _centreOfGravityHeight;
		float carDamage[5];						// Car damage: front (0), rear (1), left (2), right (3), centre (4)
		int _numberOfTyresOut;
		int isPitLimiterOn;						// Is the pit limiter on?
		float abs;								// Anti-locking braking system
		float _kersCharge;
		float _kersInput;
		int isAutoShifterOn;					// Is automatic transmission on?
		float _rideHeight[2];
		float turboBoost;						// Car turbo level
		float _ballast;
		float _airDensity;
		float airTemperature;					// Air temperature
		float roadTemperature;					// Road temperature
		float localAngularVelocity[3];			// Angular velocity vector in local coordinates
		float forceFeedback;					// Final force feedback signal
		float _performanceMeter;
		int _engineBrake;
		int _ersRecoveryLevel;
		int _ersPowerLevel;
		int _ersHeatCharging;
		int _ersIsCharging;
		float _kersCurrentKJ;
		int _drsAvailable;
		int _drsEnabled;
		float brakeTemperature[4];				// Brake disc temperature per wheel
		float clutch;							// Clutch pedal input value (0.0 to 1.0)
		float _tyreTempI[4];
		float _tyreTempM[4];
		float _tyreTempO[4];
		int isAIControlled;						// Is the car controlled by AI?
		float tyreContactPoint[4][3];			// Tyre contact point as global coordinate per wheel
		float tyreContactNormal[4][3];			// Tyre contact normal per wheel
		float tyreContactHeading[4][3];			// Tyre contact heading per wheel
		float brakeBias;						// Front brake bias
		float localVelocity[3];					// Velocity vector in local coordinates
		int _p2pActivation;
		int _p2pStatus;
		float _currentMaxRpm;
		float _mz[4];
		float _fx[4];
		float _fy[4];
		float slipRatio[4];						// Tyre slip ratio in radians per wheel
		float slipAngle[4];						// Tyre slip angle per wheel
		int _tcInAction;
		int _absInAction;
		float _suspensionDamage[4];
		float _tyreTemp[4];
		float waterTemperature;					// Water temperature
		float brakePressure[4];					// Brake pressure per wheel
		int frontBrakeCompound;					// Front break pad compound
		int rearBrakeCompound;					// Rear brake pad compound
		float brakePadWear[4];					// Brake pad wear per wheel
		float brakeDiscWear[4];					// Brake disc wear per wheel
		int isIgnitionOn;						// Is ignition switch set to on?
		int isStarterOn;						// Is starter switch set to on?
		int isEngineRunning;					// Is the engine running?
		float kerbVibrations;					// Kerb vibrations
		float slipVibrations;					// Slipping vibrations
		float gVibrations;						// G-force vibrations
		float absVibrations;					// ABS vibration
	};

	struct SPageFileGraphics
	{
		int packetId;							// Current step index
		ACC_STATUS status;						// Game status
		ACC_SESSION_TYPE session;				// Session type a.k.a. game mode
		wchar_t currentTimeText[15];			// Current lap time
		wchar_t lastTimeText[15];				// Previous lap time
		wchar_t bestTimeText[15];				// Best lap time
		wchar_t splitTimeText[15];				// Last split time
		int completedLaps;						// Number of completed laps
		int position;							// Current race position
		int currentTime;						// Current lap time in milliseconds
		int lastTime;							// Last laptime in milliseconds
		int bestTime;							// Best laptime in millisconds
		float sessionTimeLeft;					// Session time left
		float distanceTraveled;					// Distance travelled in the current stint
		int isInPit;							// Is the car pitting?
		int currentSectorIndex;					// Current track sector
		int lastSectorTime;						// Last sector time
		int numberOfLaps;						// Number of completed laps
		wchar_t tyreCompound[33];				// Tyre compound used
		float _replayTimeMultiplier;
		float normalizedCarPosition;			// Car position on track spline
		int cars;								// Number of cars on track
		float carCoordinates[60][3];			// Coordinates of cars on track
		int carID[60];							// Car IDs of cars on track
		int playerCarID;						// Player car ID
		float penaltyTime;						// The penalty time to wait
		ACC_FLAG_TYPE flag;						// Current flag
		ACC_PENALTY_TYPE penalty;				// Current penalty
		int isIdealLineOn;						// Is ideal line oN?
		int isInPitLane;						// Is in the pit lane?
		float surfaceGrip;						//Ideal line friction coefficient
		int isMandatoryPitDone;					// Is mandator pit done?
		float windSpeed;						// Wind speed in m/s
		float windDirection;					// Wind direction in radians
		int isSetupMenuVisible;					// Is player setting up the car?
		int mainDisplayIndex;					// Current car main display index
		int secondaryDisplayIndex;				// Current car secondary display index
		int tc;									// Traction control level
		int tcCut;								// Traction control cut level
		int engineMap;							// Current engine map
		int abs;								// ABS level
		float fuelPerLap;						//Average fuel consumed per lap in liters
		int isRainLightsOn;						// Is the rain lights on?
		int isFlashingLightsOn;					// Is flashing lights on?
		int lightsStage;						// Current lights stage
		float exhaustTemperature;				// Exhaust temperature
		int wiperStage;							// Current wiper stage
		int totalTimeLeft;						// Total time driver is allowed to drive in milliseconds
		int timeLeft;							// todo: Not sure how this one differs, but it's in milliseconds
		int isRainTyres;						// Is using rain tyres?
		int sessionIndex;						// Current session index
		float usedFuel;							// Used fuel since last time refueling
		wchar_t deltaLapTimeText[15];			// Delta time in text
		int deltaLapTime;						// Delta time in milliseconds
		wchar_t estimatedLapTimeText[15];		// Estimated lap time in text
		int estimatedLapTime;					// Estimated lap time in milliseconds
		int isDeltaPositive;					// Is delta time positive?
		int splitTime;							// Last split time in milliseconds
		int isValidLap;							// Is the lap valid?
		float estimatedLaps;					// Estimated laps left with remaining fuel
		wchar_t trackStatus[33];				// Track status
		int missingMandatoryPits;				// Number of mandatory pits left to do
		float clock;							// Time of day in seconds
		int isLeftBlinkerOn;					// Is left blinker on?
		int isRightBlinkerOn;					// Is right blinker on?
		int isGlobalYellow;						// Is yellow flag out?
		int isGlobalYellow1;					// Is yellow flag out in sector 1?
		int isGlobalYellow2;					// Is yellow flag out in sector 2?
		int isGlobalYellow3;					// Is yellow flag out in sector 3?
		int isGlobalWhite;						// Is white flag out?
		int isGlobalGreen;						// Is green flag out?
		int isGlobalChequered;					// Is chequered flag out?
		int isGlobalRed;						// Is red flag out?
		int mfdTyreSet;							// Number of tyre set on the MFD
		float mfdFuelToAdd;						// How much fuel to add on the MFD
		float mfdTyrePressure[4];				// Tyre pressures per wheel on the MFD
		ACC_TRACK_GRIP_STATUS trackGripStatus;	// Track grip status
		ACC_RAIN_INTENSITY rainIntensity;		// Current rain intensity
		ACC_RAIN_INTENSITY rainIntensityIn10;	// Rain intensity in 10 minutes
		ACC_RAIN_INTENSITY rainIntensityIn30;	// Rain intensity in 30 minutes
		int currentTyreSet;						// Current tyre set
		int strategyTyreSet;					// Next tyre set for pit
		int gapAhead;							// Distance in milliseconds to the car in front
		int gapBehind;							// Distance in milliseconds to the car behind
	};

#pragma pack(pop)
} // namespace wrt:acc

#endif // WRT_ACC_ACC_HPP
