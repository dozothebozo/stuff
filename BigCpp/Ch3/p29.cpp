// Draw Graphs of Curves (Adapted for SFML)
// Write a program that draws graphs of mathematical curves using the SFML library.
//
// Rules and Specifications:
// 1) Initialize an sf::RenderWindow to display your graphics.
// 2) A curve can be approximated by drawing 100 small connected line segments.
// 3) In SFML, you can use an sf::VertexArray set to the sf::LineStrip primitive
//    to draw a continuous sequence of connected lines.
// 4) Each vertex in the strip should represent the point (x, f(x)), moving to
//    the next point (x + dx, f(x + dx)).
// 5) The values of 'x' range from a minimum (xmin) to a maximum (xmax).
// 6) The step size 'dx' (the change in x) is calculated as:
//    dx = (xmax - xmin) / 100.0
// 7) Coordinate System Note: Standard math graphs place (0,0) at the center or
//    bottom-left, with 'y' going up. SFML places (0,0) at the top-left, with
//    'y' going down. You will need to scale and translate your mathematical
//    (x, y) coordinates into SFML window coordinates so the graph displays correctly.
