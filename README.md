# GNAWA-3D

## License

This project is licensed under the **MIT License**. See the `LICENSE` file for details.

## Overview
This project is a Cub3D-style 3D raycasting engine (with bonus features like textures/sky, a minimap, and an animated weapon). It renders a pseudo-3D scene from a grid-based `.cub` map using a DDA (Digital Differential Analyzer) raycasting loop.

The `src/main.c` entrypoint launches the Cub3D game (`main_cube3d`).

## Screenshots
<p float="left">
  <img src="Screenshots/Screenshot From 2026-05-26 17-55-22.png" width="32%" />
  <img src="Screenshots/Screenshot From 2026-05-26 17-55-40.png" width="32%" />
  <img src="Screenshots/Screenshot From 2026-05-26 18-05-12.png" width="32%" />
</p>



## Build

Prerequisites (based on the current `Makefile` link line):
- `cc`
- `libft/` (built via the `Makefile`)
- MinilibX for Linux in `mlx_linux/`
- SDL2 + SDL2_mixer development libs
- X11 (for MinilibX)

Build everything:
```sh
make
```

You will get the executable:
`./Gnawa3D`

## Run

Run the default bonus map:
```sh
make run
```

Run any map you want (must be a readable `.cub` file):
```sh
./Gnawa3D maps/map_bonus.cub
```

## Controls
These are the controls printed by the `Makefile`:
- `W` / `S` : move forward / move backward
- `A` / `D` : strafe left / strafe right
- `Left Arrow` / `Right Arrow` : rotate left / rotate right
- `ESC` : exit

Additional in-code behavior:
- `SPACE` is used during the intro sequence (advances intro mode).
- Mouse movement updates the view angle (relative mouse X delta).

## Map format (`.cub`)
The program expects the map file path as the only argument.

### File naming constraints
- Path must end with `.cub`
- Path must not contain spaces
- File must be readable

### Header (textures + colors)
The map file contains lines like:
- `NO <path_to_xpm>` : north texture
- `SO <path_to_xpm>` : south texture
- `WE <path_to_xpm>` : west texture
- `EA <path_to_xpm>` : east texture
- `F r,g,b` : floor color (0-255 per channel)
- `C r,g,b` : ceiling color (0-255 per channel)

Example (from `maps/map_bonus.cub`):
```txt
NO ./textures/Untitled.xpm
SO ./textures/Untitled.xpm
WE ./textures/Untitled.xpm
EA ./textures/Untitled.xpm

F 0,0,0
C 255,255,255
```

### Grid (the world)
After the header, the map is made of lines made only of:
- `1` : wall (rays stop when they hit `1`)
- `0` : empty space
- `N`, `S`, `E`, `W` : player start position and facing direction
- spaces/tabs : allowed padding inside map lines

Example:
```txt
1111111111111111111111111111111111111
1S00000000001000000000000000000000001
...
```

## Rendering algorithm (high level)
For each frame, the engine casts one ray per screen column and draws vertical slices.

1. **Ray setup**
   - `WIDTH` rays are computed across the field of view (`FOV`).
   - For a ray index `i`, the ray angle is:
     - `start_angle + i * angle_step`
   - The ray direction is derived from `cos(angle)` / `sin(angle)`.

2. **DDA grid traversal**
   - The ray starts in the player’s current map cell (`mapx`, `mapy`).
   - `deltaDistX/Y` represent the distance the ray needs to travel to cross the next grid line on each axis.
   - `stepX/stepY` indicate whether the ray moves forward or backward along each axis.
   - While the ray has not hit a wall:
     - advance to the next grid boundary (update `mapx/mapy`)
     - stop when `map[mapy][mapx] == '1'`

3. **Wall distance + perspective correction**
   - Perpendicular wall distance is computed using `sidedist - deltadist`.
   - A fish-eye correction is applied based on the angle difference between the ray and the player view direction.
   - Wall height is then computed from the distance.

4. **Texture selection and coordinates**
   - The hit “side” (x-side vs y-side) and the ray direction decide which of the 4 textures to use.
   - `wall_x` (fractional hit position) is converted into `tex_x` to sample the correct texture column.

5. **Drawing**
   - **Sky** is drawn for pixels above the wall (textured sky mapping by column/ray angle).
   - **Wall slice** is drawn as a vertical textured segment using a `tex_step` accumulator.
   - **Floor** is filled below using the floor color (`F r,g,b`).

6. **Minimap**
   - A circular minimap is drawn around the player.
   - It maps nearby world cells onto minimap pixels and also draws the player direction line.