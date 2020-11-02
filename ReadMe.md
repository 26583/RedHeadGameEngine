<h1>Welcome to my Game Engine!<h1/>
<h2>!!!This Project is currently in developement<h2/>
  <img src="documentation/TurningMineGrass.gif"/>
  <br><br>
  <div id="project-mechanic-tab" class="project-mechanics-tab">
  <h2 style="color: #363636; cursor:pointer; padding-bottom:1.5vh;" onclick="button();">Hello Cube<h2/>
    <div id="project-mechanic-info-tab">
  <p>First I created a window using SFML.<br>
    Then I drew a simple cube using a simple color shader<br> and a vertex and an index buffer.<p/>
  <img src="documentation/RHGEturning-cube.gif"/>
      <div/>
    <div/>
  <h2>Texturing<h2/>
    <p>First I had to Load an Image.<br>
      This was quite simple, I just used a simple .bmp loadingscript.<br>
      <br>
      Then I had to make a uv buffer wich was quite annoying since I was using an index buffer to use less vertices. This meant I had to also index my UV's<br>
      The funny thing is is that opengl doesn't allow multiple index buffers, so because my uv buffer was longer then my vertices buffer this proved quite diffecult.<br>
      That is also why is dicided to first focus on the texturing and fix the index buffer later.
      <br><br>Result:     
    <p/>
<img src="documentation/TurningMineGrass.gif"/>
