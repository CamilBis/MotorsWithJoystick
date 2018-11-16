/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <ctre/Phoenix.h>

class Robot : public frc::IterativeRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousDisabled();
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  WPI_TalonSRX avant_gauche(4);
  WPI_TalonSRX millieu_gauche(5);
  WPI_TalonSRX bas_gauche(6);
  WPI_TalonSRX avant_droit(1);
  WPI_TalonSRX millieu_droit(2);
  WPI_TalonSRX bas_droit(3);

  Joystick *_joystickOne;

  RobotDrive myDrive(avant_gauche, avant_droit, _joystickOne);
};