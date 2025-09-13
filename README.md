<div align="center">
  <h1>👁️ OPEN YOUR EYES</h1>
  <p><i>A 3D puzzle game for the GMTK 2025 game jam</i></p>

  <p>
    <img src="https://img.shields.io/badge/Engine-Unreal%20Engine%205-1f6feb?logo=unrealengine" alt="Unreal Engine 5 badge">
    <img src="https://img.shields.io/badge/Jam-GMTK%202025-ff69b4" alt="GMTK 2025 badge">
    <img src="https://img.shields.io/badge/Genre-3D%20Puzzle-8a2be2" alt="3D Puzzle badge">
    <a href="https://itaruf.itch.io/openyoureyes" target="_blank">
      <img src="https://img.shields.io/badge/Play%20on-itch.io-FA5C5C?logo=itch.io&logoColor=white" alt="Play on itch.io">
    </a>
  </p>
</div>

<hr>

<h2>Synopsis</h2>

<p>
  <b>OPEN YOUR EYES</b> is a 3D puzzle game developed with <b>Unreal Engine 5</b> for the GMTK 2025 game jam, which lasted 4 days and imposed the theme "LOOP".
</p>

<p>
  Meet <b>Boumax</b>, your anomaly-hunting robot on a mission to spot the smallest oddities.
  Use your jet pack to fly around the room and get ready to detect any anomaly no matter how cleverly it’s hidden !
</p>

<p>
  Will your observation skills hold up under pressure? <b>Ignite your thrusters</b>, keep your eyes open, and uncover the anomalies hiding in plain sight !
</p>

<p align="center">
  <img src="https://media0.giphy.com/media/v1.Y2lkPTc5MGI3NjExdjN5ZHhsd21nbzdtMDFmMHljdjdxb2U4OGRneTl5dGVhYzQweWs2YSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/s8ulTZD4KUhkb0EFYt/giphy.gif"
       width="720" alt="Jet pack traversal & scan loop">
</p>

<hr>

<h2>Gameplay</h2>

<h3>Controls</h3>

<table>
  <tr>
    <td><b>Move</b></td><td>W / A / S / D</td>
  </tr>
  <tr>
    <td><b>Look around</b></td><td>Mouse</td>
  </tr>
  <tr>
    <td><b>Fly: Jetpack activated !</b></td><td>Space</td>
  </tr>
  <tr>
    <td><b>Hover (while flying)</b></td><td>Left Click</td>
  </tr>
  <tr>
    <td><b>Pause</b></td><td>Esc</td>
  </tr>
</table>

<h3>Game loop</h3>

<p>
  <b>OPEN YOUR EYES</b> challenges you to explore the room, investigate the objects around you, and confirm whether one of them is touched by an anomaly by reporting to the Anomaly Reporter. A typical loop goes like this:
</p>

<ol>
  <li><b>Baseline (Day 0):</b> You first learn the room layout and object placements and looks. This becomes your reference all throughout the loop.</li>
  <li><b>Daily Check:</b> Each new day may contain an <b>anomaly</b> (or <b>no anomaly</b>). Anomalies are drawn from the set below (e.g., Position, Orientation, Scale, Texture, Hidden).</li>
  <li><b>Investigate:</b> Anything that feels “off” might be the <b>anomaly</b>. Try to remember !</li>
  <li><b>Report:</b> Go to the <b>Anomaly Reporter</b> and either confirm your suspicion by stepping on the plate labelled <b>Y</b> (YES) or the one with <b>N</b> (NO) if you believe the room is unchanged.</li>
  <li><b>Outcome:</b> A correct report advances you to the next day when no anomaly is present; if an anomaly is present and you report it correctly, you win. Any incorrect report sends you back to <b>Day 0</b>, the beginning of the loop.</li>
</ol>

<h3>Anomaly Types</h3>
<table>
  <tr><td><b>Position</b></td><td>Object is displaced somewhere else.</td></tr>
  <tr><td><b>Orientation</b></td><td>Object faces a different direction.</td></tr>
  <tr><td><b>Scale</b></td><td>Object becomes bigger or smaller.</td></tr>
  <tr><td><b>Texture</b></td><td>Material/visual surface changes.</td></tr>
  <tr><td><b>Hidden</b></td><td>Object is removed from the scene.</td></tr>
</table>

<h3>Gallery</h3>

<table>
  <tr>
    <td align="center" width="50%">
      <img src="https://github.com/user-attachments/assets/7bc50766-44ce-472b-ac94-13eb5f9436cb" width="95%" />
      <br><sub>Scanning the area from above using the jet pack</sub>
    </td>
    <td align="center" width="50%">
      <img src="https://github.com/user-attachments/assets/7748f602-d874-4f5a-bdbb-2347475c8825" width="95%" />
      <br><sub>The smallest detail can be the anomaly...</sub>
    </td>
  </tr>
  <tr>
    <td align="center" width="50%">
      <img src="https://github.com/user-attachments/assets/2138f2c3-8570-4d5f-80df-4e98d72d9776" width="95%" />
    </td>
    <td align="center" width="50%">
      <img src="https://github.com/user-attachments/assets/f881e8cd-3475-4382-ba1f-9d0a1216e638" width="95%" />
    </td>
  </tr>
</table>

<hr>

<h2>Debug Tool: Anomaly Displacement Visualizer</h2>

<p><b>To facilitate level design, OPEN YOUR EYES</b> includes a <b>debug tool</b> that visualizes how objects affected by the displacement anomaly can be repositioned and/or reoriented.</p>
<p>At each candidate position, a yellow wireframe preview retraces the object’s shape and updates in real time, so you can see exactly how it will be placed and oriented when the anomaly triggers. These visuals are editor-only and can be toggled on or off, making them a practical tool for both level design and playtesting.</p>

<table>
  <tr>
    <td align="center" width="50%">
      <img src="https://github.com/user-attachments/assets/b178de35-3666-493c-92f6-65f52721034e" width="95%" />
      <br>
      <sub>Debug view of anomaly displacement</sub>
    </td>
    <td align="center" width="50%">
      <img src="https://github.com/user-attachments/assets/452ef6a0-4190-4b07-9216-d0601b9ce53a" width="95%" />
      <br>
      <sub>Alternative debug view of anomaly displacement</sub>
    </td>
  </tr>
  <tr>
    <td align="center" width="50%">
      <img src="https://github.com/user-attachments/assets/dee6fe3b-879a-4355-8866-ee8324f3ac65" width="95%" />
      <br>
    </td>
    <td align="center" width="50%">
      <img src="https://github.com/user-attachments/assets/54cbdfed-0005-4139-8e88-982baaf7c59d" width="95%" />
      <br>
    </td>
  </tr>
</table>

<hr>

<h2>Credits</h2>
<ul>
  <li>Design: itaruf & mobyuu</li>
  <li>Art: mobyuu</li>
  <li>Programming: itaruf</li>
  <li>Engine: Unreal Engine 5</li>
</ul>

<hr>

<div align="center">
    <b>🔎 See what others miss.</b>
</div>
