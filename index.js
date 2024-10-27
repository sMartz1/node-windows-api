const mouseController = require('./build/Release/mouse_controller');

/**
 * Mueve el ratón a las coordenadas especificadas.
 * @param {number} x - Coordenada X.
 * @param {number} y - Coordenada Y.
 */
function moveMouse(x, y) {
  mouseController.moveMouse(x, y);
}

/**
 * Mueve el ratón de manera relativa desde la posición actual.
 * @param {number} deltaX - Desplazamiento en X.
 * @param {number} deltaY - Desplazamiento en Y.
 */
function moveMouseRelative(deltaX, deltaY) {
  mouseController.moveMouseRelative(deltaX, deltaY);
}

module.exports = {
  moveMouse,
  moveMouseRelative
};