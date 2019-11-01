#include "main.h"

#include "control/drive.h"
#include "control/asyncController.h"
#include "control/macro.h"
#include "control/vision.h"
#include "control/path.h"

static Path path;
static ControlAsync Thread;
static Camera CamFront(FRONTVISION);

// Ignore below. Just for testing stuff.
void tester() {
  std::cout << "Testing" << std::endl;
  Thread.hold_angle();
}

/*===========================================
  PREMADE FUNCTIONS
===========================================*/
void start() {            // Deploy and zero arm
  roller(-200);
  lockChassis();
  wait(50);
  roller(-200);
  arm(0.3, 200, 60);
  //Thread.drive(-70,100,9);
  armReset();
  wait(250);
  Thread.disable_drive();
  unlockChassis();
}

/*===========================================
  RED MATCH AUTONOMOUSES
===========================================*/
void r_s_7() {            // red small 8 cube

  start();
  Thread.disable_drive();
  roller(200);
  // Pick up 4 cubes

  drive(1300, 160, 9, 10000, 0);

  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yeet", true);
  path.del("yeet");

  drive(1400, 145, 9, 10000, 0);
  Thread.rack(RACK_TOWER-200, 120, 7);
  drive(-800, 200, 9, 10000, 0);
  roller(-15);
  Thread.disable_arm();
  turn(770, 200, 7);

  // Drive to small red corner and place
  roller(-35);
  Thread.disable_rack();
  Thread.drive(450, 120, 4);
  wait(200);
  rack(RACK_UP, 135, 7);

  // Yeet outta there
  Thread.drive(-300, 200, 10);
  roller(-200);
  rack(RACK_DOWN, 200, 15);



  // start();
  // roller(200);
  // // Pick up 4 cubes
  //
  // drive(1100, 105, 9, 10000, 0);
  //
  // // Yoink 3 more cubes and turn right facing small red corner
  // path.run("yeety", true);
  // path.del("yeety");
  //
  // drive(1200, 140, 9, 10000, 0);
  // Thread.disable_arm();
  // turn(730, 160, 7);
  //
  // // Drive to small red corner and place
  // roller(-23);
  // Thread.drive(1450, 150, 9);
  // rack(RACK_UP, 95, 6);
  //
  // // Yeet outta there
  // Thread.drive(-300, 200, 10);
  // roller(-200);
  // rack(RACK_DOWN, 200, 15);
}
void r_s_8() {            // red small 8 cube
  drive(300,200,9);
  Thread.drive(-300,200,9);
  start();
  Thread.disable_drive();
  roller(200);
  // Pick up 4 cubes

  drive(1300, 150, 9, 10000, 0);

  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yeet", true);
  path.del("yeet");

  drive(1200, 120, 9, 10000, 0);
  drive(-600, 200, 9, 10000, 0);

  Thread.disable_arm();
  turn(750, 200, 7);

  // Drive to small red corner and place
  roller(-35);
  Thread.drive(350, 100, 9);
  rack(RACK_UP, 170, 7);

  // Yeet outta there
  Thread.drive(-300, 200, 10);
  roller(-200);
  rack(RACK_DOWN, 200, 15);
}
void r_n_9() {            // Red No Score 9 Cube
  start();
  roller(200);
  // Pick up 4 cubes

  drive(1100, 105, 9, 10000, 0);


  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yeety", true);
  path.del("yeety");

  drive(1200, 140, 9, 10000, 0);
  Thread.disable_arm();
  turn(750, 160, 7);

  // Drive to small red corner and place
   drive(1300, 200, 9);
   roller(-100);


  // Yeet outta there
  drive(-300, 200, 10);
  roller(0);



}
void r_b_orange() {       // red big orange cube
  start();
  roller(100);
  drive(200,100,50);
  roller(0);
  turn(-150,100,8);
  Thread.arm(ARM_LOW_TOWER, 200, 60);
  drive(1200,200,3);
  turn(300,100,8);
  drive(200,200,3);
  roller(-200);
  drive(-250,200,6);
  turn(320,50,6);
  Thread.disable_arm();
  roller(0);
}

/*===========================================
  BLUE MATCH AUTONOMOUSES
===========================================*/
void b_s_7() {            // blue small 8 cube
  start();
  roller(200);
  // Pick up 4 cubes

  drive(1100, 105, 9, 10000, 0);

  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yeetyt", true);
  path.del("yeety");

  drive(1200, 140, 9, 10000, 0);
  Thread.disable_arm();
  turn(700, 160, 7);

  // Drive to small red corner and place
  roller(-23);
  Thread.drive(1450, 150, 9);
  rack(RACK_UP, 95, 6);

  // Yeet outta there
  Thread.drive(-300, 200, 10);
  roller(-200);
  rack(RACK_DOWN, 200, 15);
}
void b_s_8() {            // blue small 8 cube
  drive(250,200,9);
  Thread.drive(-250,200,9);
  start();
  Thread.disable_drive();
  roller(200);
  // Pick up 4 cubes

  drive(1300, 140, 9, 10000, 0);

  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yeety", true);
  path.del("yeety");

  drive(1200, 130, 9, 10000, 0);
  Thread.disable_arm();
  turn(750, 170, 7);

  // Drive to small red corner and place
  roller(-32);
  Thread.drive(1450, 145, 9);
  rack(RACK_UP, 130, 8);

  // Yeet outta there
  Thread.drive(-300, 200, 10);
  roller(-200);
  rack(RACK_DOWN, 200, 15);
}
void b_n_9() {            // Blue No Score 9 cube
  start();
  roller(200);
  // Pick up 4 cubes

  drive(1100, 105, 9, 10000, 0);


  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yote", true);
  path.del("yote");

  drive(1200, 140, 9, 10000, 0);
  Thread.disable_arm();
  turn(-680, 160, 7);

  // Drive to small red corner and place
   drive(1300, 200, 9);
   roller(-100);


  // Yeet outta there
  drive(-300, 200, 10);
  roller(0);


}
void b_b_green() {        // blue big green cube
  start();
  roller(100);
  drive(200,100,50);
  roller(0);
  turn(150,100,8);
  Thread.arm(ARM_LOW_TOWER, 200, 60);
  drive(1200,200,3);
  turn(-300,100,8);
  drive(200,200,3);
  roller(-200);
  drive(-250,200,6);
  turn(-320,50,6);
  Thread.disable_arm();
  roller(0);
}

/*===========================================
  SKILLS AUTONOMOUSES
===========================================*/
void skills1() {          // official skills

  start();

  wait(100);

  //prime robot
  roller(200);
  drive(1300,130,5);
  strafe(-80,100,5);
  drive(1200, 130, 5);
  strafe(50,100,5);
  drive(600,100,5);
  turn(520, 150, 2);
  drive(-600,100,5);
  roller(-200);
  wait(250);
  roller(0);
  Thread.drive(550,130,7);
  roller(0);
  rack(1500, 200, 11);
  wait(200);
  Thread.disable_drive();
  roller(200);
  Thread.rack(RACK_DOWN, 200, 15);
  roller(100);
  turn(70, 200, 6);
  wait(200);
  roller(10);
  wait(200);
  Thread.disable_drive();

  tower(1);
  drive(250,100,5);
  roller(-150);
  wait(400);
  Thread.drive(-250,100,5);
  armReset();
  Thread.disable_drive();
  roller(200);
  Thread.disable_rack();
  turn(-360,150,5);
  roller(0);
  roller(-31);
  Thread.drive(550, 80, 6);
  rack(RACK_UP, 135, 11);
  Thread.disable_drive();
  wait(600);
  //score 7 cubes in small blue zone
  roller(-200);
  Thread.rack(RACK_DOWN, 200, 15);
  drive(-270, 200, 9);
  wait(100);
  turn(-700, 200, 9);
  align(300, 3);
  roller(0);
  Thread.arm(1, 100, 20);
  drive(1000,200,6);
  turn(-500, 150, 7);
  align(300, 3);
  Thread.disable_arm();
  armReset();
  roller(200);
  wait(100);
  drive(1200,90,4);
  roller(100);
  wait(200);

  // Low
  tower(1);
  turn(-250, 150, 4);
  roller(-80);
  drive(150,150,8);

  // Drive to red tower and drop out cube
  drive(-150,150,4);
  roller(200);
  Thread.arm(ARM_BOTTOM-0.2, 200, 20);
  turn(260, 150, 4);
  roller(200);
  drive(1600,90,6);
  Thread.disable_arm();
  roller(100);

  wait(300);
  tower(2);

  // Lift arm to mid tower height
  turn(330,80,7);
  drive(240,150,5);
  roller(-180);

  // Spit cube into the mid tower
  wait(500);
  Thread.arm(ARM_BOTTOM-0.2, 200, 20);
  roller(200);

  drive(-700,200,5);
  wait(100);
  roller(200);
  turn(-550, 150, 7);
  Thread.drive(1000,90,5);
  roller(-30);
  rack(RACK_UP, 110, 11);
  Thread.disable_arm();

  Thread.disable_drive();
  roller(-100);
  Thread.rack(RACK_DOWN, 200, 15);
  wait(100);
  drive(-300, 200, 2);
}
