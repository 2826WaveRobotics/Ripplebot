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

#include "subsystems/Drive.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/CANSparkMaxLowLevel.h>
#include <iostream>

/**
 * Drive Subsystem implementation
 * 
 * @author 2826WaveRobotics
*/
Drive::Drive()
{
    SetName("Drive");
    SetSubsystem("Drive");

    m_motorLeftOne = new ctre::phoenix::motorcontrol::can::TalonSRX(30);
    m_motorLeftTwo = new ctre::phoenix::motorcontrol::can::TalonSRX(36);
    m_motorRightOne = new ctre::phoenix::motorcontrol::can::TalonSRX(20);
    m_motorRightTwo = new ctre::phoenix::motorcontrol::can::TalonSRX(32);
    
    // TODO: figure out how to use talons in an arcade style drive
    m_leftControllerGroup->Register(m_motorLeftOne);
    m_leftControllerGroup->Register(m_motorLeftTwo);
    m_rightControllerGroup->Register(m_motorRightOne);
    m_rightControllerGroup->Register(m_motorRightTwo);

    // m_waveDrive->SetSafetyEnabled(true);
    // m_waveDrive->SetExpiration(0.2_s);
    // m_waveDrive->SetMaxOutput(1.0);
    
    // set motor orientation
    m_motorRightOne->SetInverted(false);
    m_motorRightTwo->SetInverted(false);
    m_motorLeftOne->SetInverted(true);
    m_motorLeftTwo->SetInverted(true);
}

void Drive::Periodic() 
{
    // Put code here to be run every loop
}

void Drive::SimulationPeriodic() 
{
    // This method will be called once per scheduler run when in simulation
}

void Drive::TankDrive(double moveLeft, double moveRight)
{
    // set left motors
    m_motorLeftOne->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, moveLeft);
    m_motorLeftTwo->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, moveLeft);

    // set right motors
    m_motorRightOne->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, moveRight);
    m_motorRightTwo->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, moveRight);
}