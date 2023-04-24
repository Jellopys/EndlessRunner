# EndlessRunner
 
This is an endless runner game where you dodge the boxes coming at you and gain points each second you stay alive. You have three lives. If you get hit, you become invulnerable for 3 sec.

# Part 1
I used object pooling to place out the obstacles and sections of the game. I have an "ObjectPoolManager.cpp" that contains "ObjectPoolComponent.cpp" Components that contains the object pooling and spawning.
I created several Base classes such as BaseObstacle, BaseSection and BaseProjectile that I can make blueprints of and expand on their behaviors with class inheritance later on. The base classes inherits from "PooledObject.cpp", which makes them easier to handle.

The GameMode keeps track of the score, the difficulty and resetting the game.

During this experimentation and discovery I found Timers to be quite useful for looping or setting a normal timer for a function call.

I found that "UGameplayStatics::" Functions also to be quite handy when getting GameMode or PlayerPawn for example.

I tried to make use of "TObjectPtr<ExampleClass>" but got told from other students that using pointers with just an asterix, for example: "ExampleClass*", is handled by the engine as a "TObjectPtr" already. Which is why it's a bit of a mix of both in the project at the moment.

I went with the approach of continously moving the PLAYER forward and placing out sections in front of it with a LifeTime timer. This approach is a little fragile since I have to finetune my variables to suit the speed of the character. Also, after a certain while I would run into the max integer value of 2,147,483,647 which will crash the game. So for part 2 I need to figure out a solution of handling that.
 
 
# Part 2
Not done yet, write more about this later.

Expect; Highscore
