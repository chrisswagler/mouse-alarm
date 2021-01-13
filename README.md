# mouse-alarm
This project is a motion alarm inspired by the mouse in our apartment. The alarm was placed on the floor in a door frame so that it could be triggered when motion was detected. Because the last known location of the mouse was in a particular room, the motion detector's purpose was to alert us when the mouse presumably went to leave. 

# Functionality
<ul>
  <li>HC-SR04 distance sensor used to detect changes in measured distance</li>
  <li>Threshold value (set to 0.1) so that small fluctuations in the distance measurements would be ignored</li>
  <li>LED and buzzer triggered when measured distance less than the set distance</li>
  <li>Button used to disable alarm, but also as distance calibration for set distance</li>
</ul>

# Design Shortcomings
The mouse clearly did not stroll through our front doors, so there was no guarantee it would actually pass through the doorway that the sensor was set. The idea behind the placement of the alarm was between the two most likely locations of the mouse, so an alarm trigger would indicate our suspicions were correct. Our apartment was in fairly new condition with no visible holes or cracks, so that was the reasoning behind the assumption that the mouse could trigger the alarm. 

Because only one distance sensor was used, there wasn't a straightforward technique to determine which direction the mouse was headed. Additionally, the design would fail if the size of the mouse was within the threshold range and passed at the far end of the sensor, causing the alarm to not sound at all. 

End result: the mouse was not seen again (knock on wood) so the alarm wasn't utilized. However, the alarm was quite simple and versatile, so it could be used for other applications. 
