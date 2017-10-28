type jsUnsafe;

external toJsUnsafe : 'a => jsUnsafe = "%identity";

let unwrapValue =
  fun
  | `String(s) => toJsUnsafe(s)
  | `Bool(b) => toJsUnsafe(Js.Boolean.to_js_boolean(b))
  | `Float(f) => toJsUnsafe(f)
  | `Date(d) => toJsUnsafe(d)
  | `Callback(c) => toJsUnsafe(c)
  | `Element(e) => toJsUnsafe(e)
  | `Object(o) => toJsUnsafe(o)
  | `Enum(_) => assert false;

let optionMap = (fn, option) =>
  switch option {
  | Some(value) => Some(fn(value))
  | None => None
  };

module AppBar = {
  [@bs.module "react-toolbox/lib/app_bar"] external reactClass : ReasonReact.reactClass = "AppBar";
  let make =
      (
        ~className: option(string)=?,
        ~fixed: option(bool)=?,
        ~flat: option(bool)=?,
        ~leftIcon: option(ReasonReact.reactElement)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onLeftIconClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onRightIconClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~rightIcon: option(ReasonReact.reactElement)=?,
        ~scrollHide: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~title: option(string)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "fixed": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fixed)),
        "flat": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, flat)),
        "leftIcon": Js.Nullable.from_opt(leftIcon),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onLeftIconClick": Js.Nullable.from_opt(onLeftIconClick),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onRightIconClick": Js.Nullable.from_opt(onRightIconClick),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "rightIcon": Js.Nullable.from_opt(rightIcon),
        "scrollHide": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, scrollHide)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "title": Js.Nullable.from_opt(title)
      },
      children
    );
};

module Autocomplete = {
  module Direction = {
    type t =
      | Auto
      | Up
      | Down;
    let to_string =
      fun
      | Auto => "auto"
      | Up => "up"
      | Down => "down";
  };
  module SelectedPosition = {
    type t =
      | Above
      | Below
      | None;
    let to_string =
      fun
      | Above => "above"
      | Below => "below"
      | None => "none";
  };
  module SuggestionMatch = {
    type t =
      | Disabled
      | Start
      | Anywhere
      | Word;
    let to_string =
      fun
      | Disabled => "disabled"
      | Start => "start"
      | Anywhere => "anywhere"
      | Word => "word";
  };
  [@bs.module "react-toolbox/lib/autocomplete"] external reactClass : ReasonReact.reactClass =
    "Autocomplete";
  let make =
      (
        ~allowCreate: option(bool)=?,
        ~className: option(string)=?,
        ~direction: option(Direction.t)=?,
        ~disabled: option(bool)=?,
        ~error: option(ReasonReact.reactElement)=?,
        ~floating: option(bool)=?,
        ~hint: option(ReasonReact.reactElement)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~keepFocusOnChange: option(bool)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~maxLength: option(float)=?,
        ~multiline: option(bool)=?,
        ~multiple: option(bool)=?,
        ~name: option(string)=?,
        ~onBlur: option(((ReactEventRe.Focus.t, string) => unit))=?,
        ~onChange: option((('value, ReactEventRe.Mouse.t) => unit))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyPress: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onQueryChange: option(ReasonReact.Callback.t(string))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~required: option(bool)=?,
        ~rows: option(float)=?,
        ~selectedPosition: option(SelectedPosition.t)=?,
        ~showSelectedWhenNotInSource: option(bool)=?,
        ~showSuggestionsWhenValueIsSet: option(bool)=?,
        ~source: option('a)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~suggestionMatch: option(SuggestionMatch.t)=?,
        ~theme: option('b)=?,
        ~_type: option(string)=?,
        ~value: option('c)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "allowCreate": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, allowCreate)),
        "className": Js.Nullable.from_opt(className),
        "direction": Js.Nullable.from_opt(optionMap(Direction.to_string, direction)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "error": Js.Nullable.from_opt(error),
        "floating": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, floating)),
        "hint": Js.Nullable.from_opt(hint),
        "icon": Js.Nullable.from_opt(icon),
        "keepFocusOnChange":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, keepFocusOnChange)),
        "label": Js.Nullable.from_opt(label),
        "maxLength": Js.Nullable.from_opt(maxLength),
        "multiline": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiline)),
        "multiple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiple)),
        "name": Js.Nullable.from_opt(name),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyPress": Js.Nullable.from_opt(onKeyPress),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onQueryChange": Js.Nullable.from_opt(onQueryChange),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "rows": Js.Nullable.from_opt(rows),
        "selectedPosition":
          Js.Nullable.from_opt(optionMap(SelectedPosition.to_string, selectedPosition)),
        "showSelectedWhenNotInSource":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, showSelectedWhenNotInSource)),
        "showSuggestionsWhenValueIsSet":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, showSuggestionsWhenValueIsSet)),
        "source": Js.Nullable.from_opt(source),
        "style": Js.Nullable.from_opt(style),
        "suggestionMatch":
          Js.Nullable.from_opt(optionMap(SuggestionMatch.to_string, suggestionMatch)),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(_type),
        "value": Js.Nullable.from_opt(value)
      },
      children
    );
};

module Avatar = {
  [@bs.module "react-toolbox/lib/avatar"] external reactClass : ReasonReact.reactClass = "Avatar";
  let make =
      (
        ~className: option(string)=?,
        ~cover: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~image: option(ReasonReact.reactElement)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~title: option(string)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "cover": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, cover)),
        "icon": Js.Nullable.from_opt(icon),
        "image": Js.Nullable.from_opt(image),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "title": Js.Nullable.from_opt(title)
      },
      children
    );
};

module BrowseButton = {
  [@bs.module "react-toolbox/lib/button"] external reactClass : ReasonReact.reactClass =
    "BrowseButton";
  let make =
      (
        ~accent: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~flat: option(bool)=?,
        ~floating: option(bool)=?,
        ~href: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inverse: option(bool)=?,
        ~label: option(string)=?,
        ~mini: option(bool)=?,
        ~neutral: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~primary: option(bool)=?,
        ~raised: option(bool)=?,
        ~ripple: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "accent": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, accent)),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "flat": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, flat)),
        "floating": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, floating)),
        "href": Js.Nullable.from_opt(href),
        "icon": Js.Nullable.from_opt(icon),
        "inverse": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inverse)),
        "label": Js.Nullable.from_opt(label),
        "mini": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, mini)),
        "neutral": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, neutral)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "primary": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, primary)),
        "raised": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, raised)),
        "ripple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, ripple)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(_type)
      },
      children
    );
};

module Button = {
  [@bs.module "react-toolbox/lib/button"] external reactClass : ReasonReact.reactClass = "Button";
  let make =
      (
        ~accent: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~flat: option(bool)=?,
        ~floating: option(bool)=?,
        ~href: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inverse: option(bool)=?,
        ~label: option(string)=?,
        ~mini: option(bool)=?,
        ~neutral: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~primary: option(bool)=?,
        ~raised: option(bool)=?,
        ~ripple: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "accent": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, accent)),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "flat": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, flat)),
        "floating": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, floating)),
        "href": Js.Nullable.from_opt(href),
        "icon": Js.Nullable.from_opt(icon),
        "inverse": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inverse)),
        "label": Js.Nullable.from_opt(label),
        "mini": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, mini)),
        "neutral": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, neutral)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "primary": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, primary)),
        "raised": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, raised)),
        "ripple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, ripple)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(_type)
      },
      children
    );
};

module Card = {
  [@bs.module "react-toolbox/lib/card"] external reactClass : ReasonReact.reactClass = "Card";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~raised: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "raised": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, raised)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module CardActions = {
  [@bs.module "react-toolbox/lib/card"] external reactClass : ReasonReact.reactClass =
    "CardActions";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module CardMedia = {
  module AspectRatio = {
    type t =
      | Wide
      | Square;
    let to_string =
      fun
      | Wide => "wide"
      | Square => "square";
  };
  [@bs.module "react-toolbox/lib/card"] external reactClass : ReasonReact.reactClass = "CardMedia";
  let make =
      (
        ~aspectRatio: option(AspectRatio.t)=?,
        ~className: option(string)=?,
        ~color: option(string)=?,
        ~contentOverlay: option(bool)=?,
        ~image: option(ReasonReact.reactElement)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "aspectRatio": Js.Nullable.from_opt(optionMap(AspectRatio.to_string, aspectRatio)),
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(color),
        "contentOverlay": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, contentOverlay)),
        "image": Js.Nullable.from_opt(image),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module CardText = {
  [@bs.module "react-toolbox/lib/card"] external reactClass : ReasonReact.reactClass = "CardText";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module CardTitle = {
  [@bs.module "react-toolbox/lib/card"] external reactClass : ReasonReact.reactClass = "CardTitle";
  let make =
      (
        ~avatar: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~subtitle: option(ReasonReact.reactElement)=?,
        ~theme: option(Js.t({..}))=?,
        ~title: option(ReasonReact.reactElement)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "avatar": Js.Nullable.from_opt(avatar),
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "subtitle": Js.Nullable.from_opt(subtitle),
        "theme": Js.Nullable.from_opt(theme),
        "title": Js.Nullable.from_opt(title)
      },
      children
    );
};

module Checkbox = {
  [@bs.module "react-toolbox/lib/checkbox"] external reactClass : ReasonReact.reactClass =
    "Checkbox";
  let make =
      (
        ~checked: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onChange: option(((Js.boolean, ReactEventRe.Mouse.t) => unit))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "checked": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, checked)),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "label": Js.Nullable.from_opt(label),
        "name": Js.Nullable.from_opt(name),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module Chip = {
  [@bs.module "react-toolbox/lib/chip"] external reactClass : ReasonReact.reactClass = "Chip";
  let make =
      (
        ~className: option(string)=?,
        ~deletable: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDeleteClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "deletable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, deletable)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDeleteClick": Js.Nullable.from_opt(onDeleteClick),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module DatePicker = {
  module Locale = {
    type t =
      | De
      | No
      | En
      | Es
      | Af
      | Ar
      | Be
      | Bg
      | Bn
      | Bo
      | Br
      | Bs
      | Ca
      | Gl
      | Eu
      | Pt
      | It
      | Fr
      | Ru
      | Ua
      | Zh_cn
      | Zh_hk
      | Zh_tw;
    let to_string =
      fun
      | De => "de"
      | No => "no"
      | En => "en"
      | Es => "es"
      | Af => "af"
      | Ar => "ar"
      | Be => "be"
      | Bg => "bg"
      | Bn => "bn"
      | Bo => "bo"
      | Br => "br"
      | Bs => "bs"
      | Ca => "ca"
      | Gl => "gl"
      | Eu => "eu"
      | Pt => "pt"
      | It => "it"
      | Fr => "fr"
      | Ru => "ru"
      | Ua => "ua"
      | Zh_cn => "zh-cn"
      | Zh_hk => "zh-hk"
      | Zh_tw => "zh-tw";
  };
  [@bs.module "react-toolbox/lib/date_picker"] external reactClass : ReasonReact.reactClass =
    "DatePicker";
  let make =
      (
        ~active: option(bool)=?,
        ~autoOk: option(bool)=?,
        ~cancelLabel: option(string)=?,
        ~className: option(string)=?,
        ~disabledDates: option(array(Js.Date.t))=?,
        ~enabledDates: option(array(Js.Date.t))=?,
        ~error: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inputClassName: option(string)=?,
        ~inputFormat: option(Js.t({..}))=?,
        ~label: option(string)=?,
        ~locale: option([ | `Enum(Locale.t) | `Object(Js.t({..}))])=?,
        ~maxDate: option(Js.Date.t)=?,
        ~minDate: option(Js.Date.t)=?,
        ~name: option(string)=?,
        ~okLabel: option(string)=?,
        ~onChange: option(((Js.Date.t, ReactEventRe.Mouse.t) => unit))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDismiss: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onEscKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyPress: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onOverlayClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~readonly: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~sundayFirstDayOfWeek: option(bool)=?,
        ~theme: option(Js.t({..}))=?,
        ~value: option([ | `Date(Js.Date.t) | `String(string)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "autoOk": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, autoOk)),
        "cancelLabel": Js.Nullable.from_opt(cancelLabel),
        "className": Js.Nullable.from_opt(className),
        "disabledDates": Js.Nullable.from_opt(disabledDates),
        "enabledDates": Js.Nullable.from_opt(enabledDates),
        "error": Js.Nullable.from_opt(error),
        "icon": Js.Nullable.from_opt(icon),
        "inputClassName": Js.Nullable.from_opt(inputClassName),
        "inputFormat": Js.Nullable.from_opt(inputFormat),
        "label": Js.Nullable.from_opt(label),
        "locale":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Locale.to_string(e)))
              | x => unwrapValue(x),
              locale
            )
          ),
        "maxDate": Js.Nullable.from_opt(maxDate),
        "minDate": Js.Nullable.from_opt(minDate),
        "name": Js.Nullable.from_opt(name),
        "okLabel": Js.Nullable.from_opt(okLabel),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDismiss": Js.Nullable.from_opt(onDismiss),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onEscKeyDown": Js.Nullable.from_opt(onEscKeyDown),
        "onKeyPress": Js.Nullable.from_opt(onKeyPress),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onOverlayClick": Js.Nullable.from_opt(onOverlayClick),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "readonly": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, readonly)),
        "style": Js.Nullable.from_opt(style),
        "sundayFirstDayOfWeek":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, sundayFirstDayOfWeek)),
        "theme": Js.Nullable.from_opt(theme),
        "value": Js.Nullable.from_opt(optionMap(unwrapValue, value))
      },
      children
    );
};

module Dialog = {
  module Type = {
    type t =
      | Small
      | Normal
      | Large;
    let to_string =
      fun
      | Small => "small"
      | Normal => "normal"
      | Large => "large";
  };
  [@bs.module "react-toolbox/lib/dialog"] external reactClass : ReasonReact.reactClass = "Dialog";
  let make =
      (
        ~actions: option(array(Js.t({..})))=?,
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onEscKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onOverlayClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onOverlayMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onOverlayMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onOverlayMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~title: option(string)=?,
        ~_type: option([ | `Enum(Type.t) | `String(string)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "actions": Js.Nullable.from_opt(actions),
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onEscKeyDown": Js.Nullable.from_opt(onEscKeyDown),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onOverlayClick": Js.Nullable.from_opt(onOverlayClick),
        "onOverlayMouseDown": Js.Nullable.from_opt(onOverlayMouseDown),
        "onOverlayMouseMove": Js.Nullable.from_opt(onOverlayMouseMove),
        "onOverlayMouseUp": Js.Nullable.from_opt(onOverlayMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "title": Js.Nullable.from_opt(title),
        "type":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Type.to_string(e)))
              | x => unwrapValue(x),
              _type
            )
          )
      },
      children
    );
};

module Drawer = {
  module Type = {
    type t =
      | Left
      | Right;
    let to_string =
      fun
      | Left => "left"
      | Right => "right";
  };
  [@bs.module "react-toolbox/lib/drawer"] external reactClass : ReasonReact.reactClass = "Drawer";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~insideTree: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onOverlayClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        ~withOverlay: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "className": Js.Nullable.from_opt(className),
        "insideTree": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, insideTree)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onOverlayClick": Js.Nullable.from_opt(onOverlayClick),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, _type)),
        "withOverlay": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, withOverlay))
      },
      children
    );
};

module Dropdown = {
  [@bs.module "react-toolbox/lib/dropdown"] external reactClass : ReasonReact.reactClass =
    "Dropdown";
  let make =
      (
        ~allowBlank: option(bool)=?,
        ~auto: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~error: option(string)=?,
        ~label: option(string)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onChange: option((('value, ReactEventRe.Mouse.t) => unit))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~required: option(bool)=?,
        ~source: array('a),
        ~style: option(ReactDOMRe.style)=?,
        ~template: option(Js.t({..}))=?,
        ~theme: option(Js.t({..}))=?,
        ~value: option([ | `String(string) | `Float(float)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "allowBlank": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, allowBlank)),
        "auto": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, auto)),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "error": Js.Nullable.from_opt(error),
        "label": Js.Nullable.from_opt(label),
        "name": Js.Nullable.from_opt(name),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "source": source,
        "style": Js.Nullable.from_opt(style),
        "template": Js.Nullable.from_opt(template),
        "theme": Js.Nullable.from_opt(theme),
        "value": Js.Nullable.from_opt(optionMap(unwrapValue, value))
      },
      children
    );
};

module FontIcon = {
  [@bs.module "react-toolbox/lib/font_icon/FontIcon"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~value: option(ReasonReact.reactElement)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "value": Js.Nullable.from_opt(value)
      },
      children
    );
};

module IconButton = {
  [@bs.module "react-toolbox/lib/button"] external reactClass : ReasonReact.reactClass =
    "IconButton";
  let make =
      (
        ~accent: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~href: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inverse: option(bool)=?,
        ~neutral: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~primary: option(bool)=?,
        ~ripple: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "accent": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, accent)),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "href": Js.Nullable.from_opt(href),
        "icon": Js.Nullable.from_opt(icon),
        "inverse": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inverse)),
        "neutral": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, neutral)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "primary": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, primary)),
        "ripple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, ripple)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(_type)
      },
      children
    );
};

module IconMenu = {
  module Position = {
    type t =
      | Auto
      | Static
      | TopLeft
      | TopRight
      | BottomLeft
      | BottomRight;
    let to_string =
      fun
      | Auto => "auto"
      | Static => "static"
      | TopLeft => "topLeft"
      | TopRight => "topRight"
      | BottomLeft => "bottomLeft"
      | BottomRight => "bottomRight";
  };
  [@bs.module "react-toolbox/lib/menu"] external reactClass : ReasonReact.reactClass = "IconMenu";
  let make =
      (
        ~className: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~iconRipple: option(bool)=?,
        ~menuRipple: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onHide: option(ReasonReact.Callback.t(unit))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onSelect: option(ReasonReact.Callback.t(ReactEventRe.Selection.t))=?,
        ~onShow: option(ReasonReact.Callback.t(unit))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~position: option(Position.t)=?,
        ~selectable: option(bool)=?,
        ~selected: option('a)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "icon": Js.Nullable.from_opt(icon),
        "iconRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, iconRipple)),
        "menuRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, menuRipple)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onHide": Js.Nullable.from_opt(onHide),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onSelect": Js.Nullable.from_opt(onSelect),
        "onShow": Js.Nullable.from_opt(onShow),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "position": Js.Nullable.from_opt(optionMap(Position.to_string, position)),
        "selectable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selectable)),
        "selected": Js.Nullable.from_opt(selected),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module Input = {
  [@bs.module "react-toolbox/lib/input"] external reactClass : ReasonReact.reactClass = "Input";
  let make =
      (
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~error: option(ReasonReact.reactElement)=?,
        ~floating: option(bool)=?,
        ~hint: option(ReasonReact.reactElement)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~maxLength: option(float)=?,
        ~multiline: option(bool)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onChange: option(((string, ReactEventRe.Mouse.t) => unit))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyPress: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~required: option(bool)=?,
        ~rows: option(float)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~value: option('a)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "error": Js.Nullable.from_opt(error),
        "floating": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, floating)),
        "hint": Js.Nullable.from_opt(hint),
        "icon": Js.Nullable.from_opt(icon),
        "label": Js.Nullable.from_opt(label),
        "maxLength": Js.Nullable.from_opt(maxLength),
        "multiline": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiline)),
        "name": Js.Nullable.from_opt(name),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyPress": Js.Nullable.from_opt(onKeyPress),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "rows": Js.Nullable.from_opt(rows),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(_type),
        "value": Js.Nullable.from_opt(value)
      },
      children
    );
};

module Layout = {
  [@bs.module "react-toolbox/lib/layout"] external reactClass : ReasonReact.reactClass = "Layout";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module Link = {
  [@bs.module "react-toolbox/lib/link"] external reactClass : ReasonReact.reactClass = "Link";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~count: option(float)=?,
        ~href: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~label: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "className": Js.Nullable.from_opt(className),
        "count": Js.Nullable.from_opt(count),
        "href": Js.Nullable.from_opt(href),
        "icon": Js.Nullable.from_opt(icon),
        "label": Js.Nullable.from_opt(label),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module List = {
  [@bs.module "react-toolbox/lib/list"] external reactClass : ReasonReact.reactClass = "List";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~ripple: option(bool)=?,
        ~selectable: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "ripple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, ripple)),
        "selectable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selectable)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module ListCheckbox = {
  [@bs.module "react-toolbox/lib/list"] external reactClass : ReasonReact.reactClass =
    "ListCheckbox";
  let make =
      (
        ~caption: option(string)=?,
        ~checked: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~legend: option(string)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "caption": Js.Nullable.from_opt(caption),
        "checked": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, checked)),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "legend": Js.Nullable.from_opt(legend),
        "name": Js.Nullable.from_opt(name),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module ListDivider = {
  [@bs.module "react-toolbox/lib/list"] external reactClass : ReasonReact.reactClass =
    "ListDivider";
  let make =
      (
        ~className: option(string)=?,
        ~inset: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "inset": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inset)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module ListItemAction = {
  [@bs.module "react-toolbox/lib/list"] external reactClass : ReasonReact.reactClass =
    "ListItemAction";
  let make = (~action: option(ReasonReact.reactElement)=?, ~theme: option(Js.t({..}))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"action": Js.Nullable.from_opt(action), "theme": Js.Nullable.from_opt(theme)},
      children
    );
};

module ListItemActions = {
  module Type = {
    type t =
      | Left
      | Right;
    let to_string =
      fun
      | Left => "left"
      | Right => "right";
  };
  [@bs.module "react-toolbox/lib/list"] external reactClass : ReasonReact.reactClass =
    "ListItemActions";
  let make = (~theme: option('a)=?, ~_type: option(Type.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, _type))
      },
      children
    );
};

module ListItemContent = {
  module Type = {
    type t =
      | Auto
      | Normal
      | Large;
    let to_string =
      fun
      | Auto => "auto"
      | Normal => "normal"
      | Large => "large";
  };
  [@bs.module "react-toolbox/lib/list"] external reactClass : ReasonReact.reactClass =
    "ListItemContent";
  let make =
      (
        ~caption: option(ReasonReact.reactElement)=?,
        ~legend: option(string)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "caption": Js.Nullable.from_opt(caption),
        "legend": Js.Nullable.from_opt(legend),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, _type))
      },
      children
    );
};

module ListItemLayout = {
  [@bs.module "react-toolbox/lib/list"] external reactClass : ReasonReact.reactClass =
    "ListItemLayout";
  let make =
      (
        ~avatar: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~caption: option(string)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~itemContent: option(Js.t({..}))=?,
        ~leftActions: option(array(ReasonReact.reactElement))=?,
        ~leftIcon: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~legend: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~rightActions: option(array(ReasonReact.reactElement))=?,
        ~rightIcon: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~selectable: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option('a)=?,
        ~_to: option(string)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "avatar": Js.Nullable.from_opt(optionMap(unwrapValue, avatar)),
        "caption": Js.Nullable.from_opt(caption),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "itemContent": Js.Nullable.from_opt(itemContent),
        "leftActions": Js.Nullable.from_opt(leftActions),
        "leftIcon": Js.Nullable.from_opt(optionMap(unwrapValue, leftIcon)),
        "legend": Js.Nullable.from_opt(legend),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "rightActions": Js.Nullable.from_opt(rightActions),
        "rightIcon": Js.Nullable.from_opt(optionMap(unwrapValue, rightIcon)),
        "selectable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selectable)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "to": Js.Nullable.from_opt(_to)
      },
      children
    );
};

module ListItemText = {
  [@bs.module "react-toolbox/lib/list"] external reactClass : ReasonReact.reactClass =
    "ListItemText";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~primary: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "primary": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, primary)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module ListSubHeader = {
  [@bs.module "react-toolbox/lib/list"] external reactClass : ReasonReact.reactClass =
    "ListSubHeader";
  let make =
      (
        ~caption: option(string)=?,
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "caption": Js.Nullable.from_opt(caption),
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module Menu = {
  module Position = {
    type t =
      | Auto
      | Static
      | TopLeft
      | TopRight
      | BottomLeft
      | BottomRight;
    let to_string =
      fun
      | Auto => "auto"
      | Static => "static"
      | TopLeft => "topLeft"
      | TopRight => "topRight"
      | BottomLeft => "bottomLeft"
      | BottomRight => "bottomRight";
  };
  [@bs.module "react-toolbox/lib/menu"] external reactClass : ReasonReact.reactClass = "Menu";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onHide: option(ReasonReact.Callback.t(unit))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onSelect: option(ReasonReact.Callback.t('value))=?,
        ~onShow: option(ReasonReact.Callback.t(unit))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~outline: option(bool)=?,
        ~position: option(Position.t)=?,
        ~ripple: option(bool)=?,
        ~selectable: option(bool)=?,
        ~selected: option('a)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onHide": Js.Nullable.from_opt(onHide),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onSelect": Js.Nullable.from_opt(onSelect),
        "onShow": Js.Nullable.from_opt(onShow),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "outline": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, outline)),
        "position": Js.Nullable.from_opt(optionMap(Position.to_string, position)),
        "ripple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, ripple)),
        "selectable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selectable)),
        "selected": Js.Nullable.from_opt(selected),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module MenuDivider = {
  [@bs.module "react-toolbox/lib/menu"] external reactClass : ReasonReact.reactClass =
    "MenuDivider";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module MenuItem = {
  [@bs.module "react-toolbox/lib/menu"] external reactClass : ReasonReact.reactClass = "MenuItem";
  let make =
      (
        ~caption: string,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~selected: option(bool)=?,
        ~shortcut: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "caption": caption,
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "icon": Js.Nullable.from_opt(icon),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "shortcut": Js.Nullable.from_opt(shortcut),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module NavDrawer = {
  module PermanentAt = {
    type t =
      | Sm
      | SmTablet
      | Md
      | Lg
      | LgTablet
      | Xl
      | Xxl
      | Xxxl;
    let to_string =
      fun
      | Sm => "sm"
      | SmTablet => "smTablet"
      | Md => "md"
      | Lg => "lg"
      | LgTablet => "lgTablet"
      | Xl => "xl"
      | Xxl => "xxl"
      | Xxxl => "xxxl";
  };
  module Type = {
    type t =
      | Left
      | Right;
    let to_string =
      fun
      | Left => "left"
      | Right => "right";
  };
  [@bs.module "react-toolbox/lib/layout"] external reactClass : ReasonReact.reactClass =
    "NavDrawer";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~clipped: option(bool)=?,
        ~insideTree: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onOverlayClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~permanentAt: option(PermanentAt.t)=?,
        ~pinned: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        ~withOverlay: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "className": Js.Nullable.from_opt(className),
        "clipped": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, clipped)),
        "insideTree": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, insideTree)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onOverlayClick": Js.Nullable.from_opt(onOverlayClick),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "permanentAt": Js.Nullable.from_opt(optionMap(PermanentAt.to_string, permanentAt)),
        "pinned": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, pinned)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, _type)),
        "withOverlay": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, withOverlay))
      },
      children
    );
};

module Navigation = {
  module Type = {
    type t =
      | Vertical
      | Horizontal;
    let to_string =
      fun
      | Vertical => "vertical"
      | Horizontal => "horizontal";
  };
  [@bs.module "react-toolbox/lib/navigation"] external reactClass : ReasonReact.reactClass =
    "Navigation";
  let make =
      (
        ~actions: option(array('a))=?,
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~routes: option(array('b))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "actions": Js.Nullable.from_opt(actions),
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "routes": Js.Nullable.from_opt(routes),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, _type))
      },
      children
    );
};

module Overlay = {
  [@bs.module "react-toolbox/lib/overlay"] external reactClass : ReasonReact.reactClass =
    "Overlay";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~invisible: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onEscKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "className": Js.Nullable.from_opt(className),
        "invisible": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, invisible)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onEscKeyDown": Js.Nullable.from_opt(onEscKeyDown),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module Panel = {
  [@bs.module "react-toolbox/lib/layout"] external reactClass : ReasonReact.reactClass = "Panel";
  let make =
      (
        ~bodyScroll: option(bool)=?,
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "bodyScroll": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, bodyScroll)),
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module Portal = {
  [@bs.module "react-toolbox/lib/hoc/Portal"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~container: option('a)=?,
        ~lockBody: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "container": Js.Nullable.from_opt(container),
        "lockBody": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, lockBody)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style)
      },
      children
    );
};

module ProgressBar = {
  module Mode = {
    type t =
      | Determinate
      | Indeterminate;
    let to_string =
      fun
      | Determinate => "determinate"
      | Indeterminate => "indeterminate";
  };
  module Type = {
    type t =
      | Linear
      | Circular;
    let to_string =
      fun
      | Linear => "linear"
      | Circular => "circular";
  };
  [@bs.module "react-toolbox/lib/progress_bar"] external reactClass : ReasonReact.reactClass =
    "ProgressBar";
  let make =
      (
        ~buffer: option(float)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~max: option(float)=?,
        ~min: option(float)=?,
        ~mode: option(Mode.t)=?,
        ~multicolor: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        ~value: option(float)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "buffer": Js.Nullable.from_opt(buffer),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "max": Js.Nullable.from_opt(max),
        "min": Js.Nullable.from_opt(min),
        "mode": Js.Nullable.from_opt(optionMap(Mode.to_string, mode)),
        "multicolor": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multicolor)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, _type)),
        "value": Js.Nullable.from_opt(value)
      },
      children
    );
};

module RadioButton = {
  [@bs.module "react-toolbox/lib/radio"] external reactClass : ReasonReact.reactClass =
    "RadioButton";
  let make =
      (
        ~checked: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option('a)=?,
        ~value: option('b)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "checked": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, checked)),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "label": Js.Nullable.from_opt(label),
        "name": Js.Nullable.from_opt(name),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "value": Js.Nullable.from_opt(value)
      },
      children
    );
};

module RadioGroup = {
  [@bs.module "react-toolbox/lib/radio/RadioGroup"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~name: option(string)=?,
        ~onChange: option(ReasonReact.Callback.t(string))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~value: option('a)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "name": Js.Nullable.from_opt(name),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "value": Js.Nullable.from_opt(value)
      },
      children
    );
};

module Sidebar = {
  module PermanentAt = {
    type t =
      | Sm
      | SmTablet
      | Md
      | Lg
      | LgTablet
      | Xl
      | Xxl
      | Xxxl;
    let to_string =
      fun
      | Sm => "sm"
      | SmTablet => "smTablet"
      | Md => "md"
      | Lg => "lg"
      | LgTablet => "lgTablet"
      | Xl => "xl"
      | Xxl => "xxl"
      | Xxxl => "xxxl";
  };
  module Type = {
    type t =
      | Left
      | Right;
    let to_string =
      fun
      | Left => "left"
      | Right => "right";
  };
  [@bs.module "react-toolbox/lib/layout"] external reactClass : ReasonReact.reactClass = "Sidebar";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~clipped: option(bool)=?,
        ~insideTree: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onOverlayClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~permanentAt: option(PermanentAt.t)=?,
        ~pinned: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        ~width: option(float)=?,
        ~withOverlay: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "className": Js.Nullable.from_opt(className),
        "clipped": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, clipped)),
        "insideTree": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, insideTree)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onOverlayClick": Js.Nullable.from_opt(onOverlayClick),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "permanentAt": Js.Nullable.from_opt(optionMap(PermanentAt.to_string, permanentAt)),
        "pinned": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, pinned)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, _type)),
        "width": Js.Nullable.from_opt(width),
        "withOverlay": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, withOverlay))
      },
      children
    );
};

module Slider = {
  [@bs.module "react-toolbox/lib/slider"] external reactClass : ReasonReact.reactClass = "Slider";
  let make =
      (
        ~buffer: option(float)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~editable: option(bool)=?,
        ~max: option(float)=?,
        ~min: option(float)=?,
        ~onChange: option(((float, ReactEventRe.Focus.t) => unit))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStop: option(ReasonReact.Callback.t(unit))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~pinned: option(bool)=?,
        ~snaps: option(bool)=?,
        ~step: option(float)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~value: option(float)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "buffer": Js.Nullable.from_opt(buffer),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "editable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, editable)),
        "max": Js.Nullable.from_opt(max),
        "min": Js.Nullable.from_opt(min),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDragStop": Js.Nullable.from_opt(onDragStop),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "pinned": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, pinned)),
        "snaps": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, snaps)),
        "step": Js.Nullable.from_opt(step),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "value": Js.Nullable.from_opt(value)
      },
      children
    );
};

module Snackbar = {
  module Type = {
    type t =
      | Accept
      | Cancel
      | Warning;
    let to_string =
      fun
      | Accept => "accept"
      | Cancel => "cancel"
      | Warning => "warning";
  };
  [@bs.module "react-toolbox/lib/snackbar"] external reactClass : ReasonReact.reactClass =
    "Snackbar";
  let make =
      (
        ~action: option(string)=?,
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~label: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTimeout: option(ReasonReact.Callback.t(unit))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~timeout: option(float)=?,
        ~_type: option(Type.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "action": Js.Nullable.from_opt(action),
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "className": Js.Nullable.from_opt(className),
        "label": Js.Nullable.from_opt(label),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTimeout": Js.Nullable.from_opt(onTimeout),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme),
        "timeout": Js.Nullable.from_opt(timeout),
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, _type))
      },
      children
    );
};

module Switch = {
  [@bs.module "react-toolbox/lib/switch"] external reactClass : ReasonReact.reactClass = "Switch";
  let make =
      (
        ~checked: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~label: option(string)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onChange: option(((Js.boolean, ReactEventRe.Mouse.t) => unit))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "checked": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, checked)),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "label": Js.Nullable.from_opt(label),
        "name": Js.Nullable.from_opt(name),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module Tab = {
  [@bs.module "react-toolbox/lib/tabs"] external reactClass : ReasonReact.reactClass = "Tab";
  let make =
      (
        ~active: option(bool)=?,
        ~activeClassName: option(string)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~hidden: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~label: string,
        ~onActive: option(ReasonReact.Callback.t(unit))=?,
        ~onClick: option(((ReactEventRe.Mouse.t, float) => unit))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "activeClassName": Js.Nullable.from_opt(activeClassName),
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "hidden": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, hidden)),
        "icon": Js.Nullable.from_opt(icon),
        "label": label,
        "onActive": Js.Nullable.from_opt(onActive),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module TabContent = {
  [@bs.module "react-toolbox/lib/tabs"] external reactClass : ReasonReact.reactClass =
    "TabContent";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~tabIndex: option(float)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "className": Js.Nullable.from_opt(className),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "tabIndex": Js.Nullable.from_opt(tabIndex),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module Table = {
  [@bs.module "react-toolbox/lib/table"] external reactClass : ReasonReact.reactClass = "Table";
  let make =
      (
        ~className: option(string)=?,
        ~multiSelectable: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onRowSelect: option(ReasonReact.Callback.t(array(float)))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~selectable: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "multiSelectable":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiSelectable)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onRowSelect": Js.Nullable.from_opt(onRowSelect),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "selectable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selectable)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module TableCell = {
  module Sorted = {
    type t =
      | Asc
      | Desc;
    let to_string =
      fun
      | Asc => "asc"
      | Desc => "desc";
  };
  module TagName = {
    type t =
      | Td
      | Th;
    let to_string =
      fun
      | Td => "td"
      | Th => "th";
  };
  [@bs.module "react-toolbox/lib/table"] external reactClass : ReasonReact.reactClass =
    "TableCell";
  let make =
      (
        ~className: option(string)=?,
        ~column: option(float)=?,
        ~numeric: option(bool)=?,
        ~onClick: option(((ReactEventRe.Mouse.t, float, float) => unit))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~row: option(float)=?,
        ~sorted: option(Sorted.t)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~tagName: option(TagName.t)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "column": Js.Nullable.from_opt(column),
        "numeric": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, numeric)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "row": Js.Nullable.from_opt(row),
        "sorted": Js.Nullable.from_opt(optionMap(Sorted.to_string, sorted)),
        "style": Js.Nullable.from_opt(style),
        "tagName": Js.Nullable.from_opt(optionMap(TagName.to_string, tagName)),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module TableHead = {
  [@bs.module "react-toolbox/lib/table"] external reactClass : ReasonReact.reactClass =
    "TableHead";
  let make =
      (
        ~className: option(string)=?,
        ~displaySelect: option(bool)=?,
        ~multiSelectable: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onSelect: option(((Js.boolean, ReactEventRe.Mouse.t) => unit))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~selectable: option(bool)=?,
        ~selected: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "displaySelect": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, displaySelect)),
        "multiSelectable":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiSelectable)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onSelect": Js.Nullable.from_opt(onSelect),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "selectable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selectable)),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module TableRow = {
  [@bs.module "react-toolbox/lib/table"] external reactClass : ReasonReact.reactClass = "TableRow";
  let make =
      (
        ~className: option(string)=?,
        ~idx: option(float)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onSelect: option(((float, Js.boolean) => unit))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~selectable: option(bool)=?,
        ~selected: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "idx": Js.Nullable.from_opt(idx),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onSelect": Js.Nullable.from_opt(onSelect),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "selectable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selectable)),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module Tabs = {
  module HideMode = {
    type t =
      | Display
      | Unmounted;
    let to_string =
      fun
      | Display => "display"
      | Unmounted => "unmounted";
  };
  [@bs.module "react-toolbox/lib/tabs"] external reactClass : ReasonReact.reactClass = "Tabs";
  let make =
      (
        ~className: option(string)=?,
        ~disableAnimatedBottomBorder: option(bool)=?,
        ~fixed: option(bool)=?,
        ~hideMode: option(HideMode.t)=?,
        ~index: option(float)=?,
        ~inverse: option(bool)=?,
        ~onChange: option(ReasonReact.Callback.t(float))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onContextMenu: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDoubleClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrag: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnd: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragExit: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDragStart: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDrop: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseMove: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOut: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseOver: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchCancel: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disableAnimatedBottomBorder":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableAnimatedBottomBorder)),
        "fixed": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fixed)),
        "hideMode": Js.Nullable.from_opt(optionMap(HideMode.to_string, hideMode)),
        "index": Js.Nullable.from_opt(index),
        "inverse": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inverse)),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onContextMenu": Js.Nullable.from_opt(onContextMenu),
        "onDoubleClick": Js.Nullable.from_opt(onDoubleClick),
        "onDrag": Js.Nullable.from_opt(onDrag),
        "onDragEnd": Js.Nullable.from_opt(onDragEnd),
        "onDragEnter": Js.Nullable.from_opt(onDragEnter),
        "onDragExit": Js.Nullable.from_opt(onDragExit),
        "onDragLeave": Js.Nullable.from_opt(onDragLeave),
        "onDragOver": Js.Nullable.from_opt(onDragOver),
        "onDragStart": Js.Nullable.from_opt(onDragStart),
        "onDrop": Js.Nullable.from_opt(onDrop),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseMove": Js.Nullable.from_opt(onMouseMove),
        "onMouseOut": Js.Nullable.from_opt(onMouseOut),
        "onMouseOver": Js.Nullable.from_opt(onMouseOver),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchCancel": Js.Nullable.from_opt(onTouchCancel),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "style": Js.Nullable.from_opt(style),
        "theme": Js.Nullable.from_opt(theme)
      },
      children
    );
};

module TimePicker = {
  module Format = {
    type t =
      | V_24hr
      | Ampm;
    let to_string =
      fun
      | V_24hr => "24hr"
      | Ampm => "ampm";
  };
  [@bs.module "react-toolbox/lib/time_picker"] external reactClass : ReasonReact.reactClass =
    "TimePicker";
  let make =
      (
        ~active: option(bool)=?,
        ~cancelLabel: option(string)=?,
        ~error: option(string)=?,
        ~format: option(Format.t)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inputClassName: option(string)=?,
        ~label: option(string)=?,
        ~okLabel: option(string)=?,
        ~onChange: option(((Js.Date.t, ReactEventRe.Mouse.t) => unit))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDismiss: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onEscKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyPress: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onOverlayClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~readonly: option(bool)=?,
        ~theme: option(Js.t({..}))=?,
        ~value: option(Js.Date.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "cancelLabel": Js.Nullable.from_opt(cancelLabel),
        "error": Js.Nullable.from_opt(error),
        "format": Js.Nullable.from_opt(optionMap(Format.to_string, format)),
        "icon": Js.Nullable.from_opt(icon),
        "inputClassName": Js.Nullable.from_opt(inputClassName),
        "label": Js.Nullable.from_opt(label),
        "okLabel": Js.Nullable.from_opt(okLabel),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "onDismiss": Js.Nullable.from_opt(onDismiss),
        "onEscKeyDown": Js.Nullable.from_opt(onEscKeyDown),
        "onKeyPress": Js.Nullable.from_opt(onKeyPress),
        "onOverlayClick": Js.Nullable.from_opt(onOverlayClick),
        "readonly": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, readonly)),
        "theme": Js.Nullable.from_opt(theme),
        "value": Js.Nullable.from_opt(value)
      },
      children
    );
};
