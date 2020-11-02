<div id="project-mechanic-tab" class="project-mechanics-tab">
<h1 style="color: #363636; cursor:pointer; padding-bottom:1.5vh;" onclick="button();">Welcome to my Game Engine!<h1/>
<div id="project-mechanic-info-tab">
<h2>!!!This Project is currently in developement</h2>
  
  <h2 >Hello Cube<h2/>
  <p>First I created a window using SFML.<br>
    Then I drew a simple cube using a simple color shader<br> and a vertex and an index buffer.<p/>
  <img src="https://raw.githubusercontent.com/26583/RedHeadGameEngine/master/documentation/RHGEturning-cube.gif"/>
  <h2 >Texturing<h2/>
    <p>First I had to Load an Image.<br>
      This was quite simple, I just used a simple .bmp loadingscript.<br>
      <br>
      Then I had to make a uv buffer wich was quite annoying since I was using an index buffer to use less vertices. This meant I had to also index my UV's<br>
      The funny thing is is that opengl doesn't allow multiple index buffers, so because my uv buffer was longer then my vertices buffer this proved quite diffecult.<br>
      That is also why is dicided to first focus on the texturing and fix the index buffer later.
      <br><br>Result:     
    <p/>
<img src="https://raw.githubusercontent.com/26583/RedHeadGameEngine/master/documentation/TurningMineGrass.gif"/>
    <h2>Currently working on: Architecture;<h2/>
    </div>
   </div>
