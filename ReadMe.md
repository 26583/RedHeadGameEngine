<div id="project-mechanic-tab" class="project-mechanics-tab">
<h1 style="color: #363636; cursor:pointer; padding-bottom:1.5vh;" onclick="button();">Welcome to my Game Engine!</h1>
<div style="display:block;" id="project-mechanic-info-tab">
<h2>!!!This Project is currently in developement</h2>
  
  <h2 color="red";>Hello Cube<h2/>
  <p>First I created a window using SFML.<br>
    Then I drew a simple cube using a simple color shader<br> and a vertex and an index buffer.<p/>
  <img src="https://raw.githubusercontent.com/26583/RedHeadGameEngine/master/documentation/RHGEturning-cube.gif"/>
  <h2 >Texturing<h2/>
    <p>First I had to load an Image.<br>
      This was quite simple, I just used a simple .bmp loadingscript.<br>
      <br>
      Then I had to make a uv buffer wich was quite annoying since I was using an index buffer to use less vertices. This meant I had to also index my UV's.<br>
      The funny thing is is that opengl doesn't allow multiple index buffers, so because my uv buffer was longer then my vertices buffer this proved quite difficult.<br>
      That is also why is decided to first focus on the texturing and fix the index buffer later.
      <br><br>Result:     
    <p/>
<img src="https://raw.githubusercontent.com/26583/RedHeadGameEngine/master/documentation/TurningMineGrass.gif"/>
    <h2>Depth Buffer<h2/>
      <p>I first had a problem that my cubes were being drawn on top of each other in a random order.
        So I added a Depth Buffer but for some reason it didn't work<p/>
      <img src="https://raw.githubusercontent.com/26583/RedHeadGameEngine/master/documentation/NoDepthBuffer.PNG"/>
      <p>The problem was that I had to create a depth buffer for the depth buffer to write to<p/>
      <img src="https://raw.githubusercontent.com/26583/RedHeadGameEngine/master/documentation/DepthBufferBits.PNG"/>
      <p>After I created a depth buffer through the SFML window settings, everything worked fine<p/>
      <img src="https://raw.githubusercontent.com/26583/RedHeadGameEngine/master/documentation/DepthBuffer.PNG"/>
      <h2>Currently working on: Architecture;<h2/>
    </div>
   </div>
