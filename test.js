const { moveMouse, moveMouseRelative } = require('./index');

console.log('Moviendo el ratón a la posición (300, 300)');
moveMouse(300, 300);

setTimeout(() => {
  console.log('Moviendo el ratón de manera relativa (+50, +50)');
  moveMouseRelative(50, 50);
}, 2000);