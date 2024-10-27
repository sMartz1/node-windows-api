#include <node.h>
#include <windows.h>

namespace mouse_controller {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::Value;

/**
 * Mueve el ratón a una posición absoluta (x, y)
 */
void MoveMouse(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.Length() < 2) {
    isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Se necesitan dos argumentos: x e y").ToLocalChecked()));
    return;
  }

  int x = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  int y = args[1]->NumberValue(isolate->GetCurrentContext()).FromJust();

  SetCursorPos(x, y);
}

/**
 * Mueve el ratón de manera relativa con respecto a la posición actual.
 */
void MoveMouseRelative(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.Length() < 2) {
    isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Se necesitan dos argumentos: deltaX y deltaY").ToLocalChecked()));
    return;
  }

  int deltaX = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
  int deltaY = args[1]->NumberValue(isolate->GetCurrentContext()).FromJust();

  // Obtener la posición actual del ratón
  POINT cursorPos;
  if (GetCursorPos(&cursorPos)) {
    // Calcular la nueva posición sumando deltaX y deltaY
    int newX = cursorPos.x + deltaX;
    int newY = cursorPos.y + deltaY;

    // Mover el ratón a la nueva posición
    SetCursorPos(newX, newY);
  } else {
    isolate->ThrowException(v8::Exception::Error(
        v8::String::NewFromUtf8(isolate, "No se pudo obtener la posición actual del ratón").ToLocalChecked()));
  }
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "moveMouse", MoveMouse);
  NODE_SET_METHOD(exports, "moveMouseRelative", MoveMouseRelative);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace mouse_controller