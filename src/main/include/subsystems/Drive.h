// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Subsystem.
#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include <ctre/phoenix/motorcontrol/GroupMotorControllers.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

/**
 * Drive Subsystem header file declaring associated functions and 
 * member variables
 *
 * @author 2826WaveRobotics
 */
class Drive: public frc2::SubsystemBase 
{
    public:

        Drive();

        void Periodic() override;
        void SimulationPeriodic() override;

        void TankDrive(double moveRight ,double moveLeft);

    private:

        ctre::phoenix::motorcontrol::can::TalonSRX *m_motorLeftOne;
        ctre::phoenix::motorcontrol::can::TalonSRX *m_motorLeftTwo;
        ctre::phoenix::motorcontrol::can::TalonSRX *m_motorRightOne;
        ctre::phoenix::motorcontrol::can::TalonSRX *m_motorRightTwo;

        double m_leftMotorSpeed;
        double m_rightMotorSpeed;

        // TODO: create an arcade drive using Talon SRX
        ctre::phoenix::motorcontrol::GroupMotorControllers *m_leftControllerGroup;
        ctre::phoenix::motorcontrol::GroupMotorControllers *m_rightControllerGroup;
};