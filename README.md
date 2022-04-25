# instrumpkin
The worlds first musical pumpkin!

## Background
This project originated from a digital arts class taken my sophomore year at the University of Iowa. The course had a final project which involved taking components learned throughout the semester to create something new and functional. This open-ended assignment allowed full creative freedom to build whatever we'd like, then present and demonstrate these projects to the class as our 'final'.

## Design
The direction of this project was to create an unconvential instrument. Leverging arduino and Max (by Cycling 74), my goal was to create a musical instrument out of a pumpkin (This was a fall semester course so it was somewhat relevant to Halloween).

### Diagram
The following was my initial sketch of how I imagined the design of this musical pumpkin:
![Initial pumpkin diagram](https://raw.githubusercontent.com/bmanTM/instrumpkin/45e1f4ea7b41479f675dab53adc8ef177cf7491f/demos/project_diagram.svg)
<br>
As depicted, the pumpkin would consist of a left and right vibration sensor for detecting when the user hit the pumpkin, and displays for mouth and eyes which would respond acccording to physical interaction. Vibration intensity would be sent to a connected computer which would be running a Max patch processing it into audio output.

## Final Design
Vibration sensors were replaced with a single microphone for final design. Below is a basic outline of how the system was built:
![final diagram](https://raw.githubusercontent.com/bmanTM/instrumpkin/2e3b48880942b0b04c983ad64d553cc3dc4fead3/demos/final_diagram.svg)

### Hardware Used
- 2 x [ELEGOO UNO R3 Board](https://www.amazon.com/gp/product/B01EWOE0UU/ref=ppx_yo_dt_b_asin_title_o03_s01?ie=UTF8&psc=1) - Driving eye and mouth LCDs
- 2 x [KEYESTUDIO TFT LCD](https://www.amazon.com/gp/product/B089SGJKB1/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1) - Eye LCD
- 1 x [HiLetgo TFT LCD](https://www.amazon.com/gp/product/B073R7Q8FF/ref=ppx_yo_dt_b_asin_title_o04_s01?ie=UTF8&psc=1) - Mouth LCD
- 1 x Microphone, connects to audio-in on computer.
- 1 x Speaker, connects to audio-out on computer.

### Demo
Here's a brief video of the instrument being played!
[![demo video](https://youtu.be/yttGHyif5KA)](https://youtu.be/yttGHyif5KA)
