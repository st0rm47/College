# To create bouncing ball animation in Macromedia Director

## Objective
- To create a bouncing ball animation in Macromedia Director.
- To understand the basic principles of animation and motion in digital media.

## Introduction
Computer-based animations are created by altering the properties of objects over time. A fundamental concept in animation is tweening, which refers to defining the starting and ending positions of an object and allowing the software to automatically generate the intermediate frames.

Interpolation is a key process in this workflow, ensuring that the motion between keyframes is smooth and continuous. Interpolation adjusts the object's position, rotation, size, and other properties to create fluid transitions.

Steps of computer-based animation:
- Input Process – Drawings are digitized via scanning, tracing, or digital tools. Post-processing removes errors for cleaner input.

- Composition Stage – Foreground and background elements are combined. A pencil test previews animation using pan-zoom features at low resolution.

- In-between Process – Intermediate frames are generated through interpolation (linear or spline) to create smooth motion. Skeleton-based interpolation is used in 2D, while 3D interpolation is more complex.

- Changing Colors – Color Look-Up Tables (CLUT) enable fast color changes without redrawing frames, improving efficiency with double buffering.

<div align="center">
  <img src="image.png" alt="Image" width="400" >
</div>

## Materials
- Software: Macromedia Director

## Procedure
1. Open Macromedia Director and create a new project.
2. Select the filled ellipse tool and draw a ball on the stage.
3. Right-click on the ball and convert it into a sprite.
4. Click on the left corner and drag a line to create a motion path for the ball.
5. On the score window, insert a keyframe at the starting position of the ball.
6. Change the position of the ball at equal intervals along the motion path and insert keyframes.
7. Repeat steps 4-6 to create multiple frames with different positions for the ball.
8. Play the animation to see the ball moving between the keyframes.
9. Save the project and export the animation as .avi file.

## Output
<div align="center">
  <img src="BouncingBall.gif" alt="Bouncing Ball" width="400" >
</div>

## Shortcut Keys
- Ctrl + N: Create a new project
- Ctrl + Alt + K: Insert a keyframe
- Ctrl + Shift + K: Tweaking the keyframe
- Ctrl + Shift + ] : Insert a frame
- Ctrl + Alt + P: Play the animation

## Tools Used
- Filled ellipse tool: To draw the ball
- Stage: To position and animate the ball
- Score window: To manage the timeline and keyframes
- Internal Cast: To store and manage media assets
- Playback controls: To play, pause, and navigate the animation

## Discussion
Macromedia Director is a powerful tool for creating interactive multimedia content, including animations and games. By understanding the basic principles of animation and motion, users can create engaging and dynamic animations. One of the challenges in this animation is achieving a natural motion with proper easing and squash-and-stretch effects. The advantage of using Macromedia Director lies in its interactive capabilities, allowing users to fine-tune motion dynamics and incorporate user interactions for enhanced realism.

## Conclusion
Creating a bouncing ball animation in Macromedia Director involves defining keyframes and adjusting the ball's position over time. By utilizing the software's timeline and keyframe tools, users can create smooth and dynamic animations. Mastering these techniques helps in developing more advanced animations and interactive content.

## References
- Macromedia Director User Manual
- Animation Principles and Techniques
- Notes from Multimedia Design Class


