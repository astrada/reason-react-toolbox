type jsUnsafe;

external toJsUnsafe : 'a => jsUnsafe = "%identity";

let unwrapValue =
  fun
  | `String s => toJsUnsafe s
  | `Bool b => toJsUnsafe (Js.Boolean.to_js_boolean b)
  | `Float f => toJsUnsafe f
  | `Date d => toJsUnsafe d
  | `Callback c => toJsUnsafe c
  | `Element e => toJsUnsafe e
  | `Object o => toJsUnsafe o
  | `Enum _ => assert false;

let optionMap fn option =>
  switch option {
  | Some value => Some (fn value)
  | None => None
  };

module ThemeProvider = {
  type theme;
  external themeProvider : ReasonReact.reactClass =
    "ThemeProvider" [@@bs.module "react-css-themr/lib/index"];
  let make theme::(theme: theme) children =>
    ReasonReact.wrapJsForReason reactClass::themeProvider props::{"theme": theme} children;
};

module AppBar = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/app_bar/AppBar"];
  let make
      className::(className: option string)=?
      fixed::(fixed: option bool)=?
      flat::(flat: option bool)=?
      leftIcon::(leftIcon: option ReasonReact.reactElement)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onLeftIconClick::(onLeftIconClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onRightIconClick::(onRightIconClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      rightIcon::(rightIcon: option ReasonReact.reactElement)=?
      scrollHide::(scrollHide: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      title::(title: option string)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "fixed": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean fixed),
        "flat": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean flat),
        "leftIcon": Js.Null_undefined.from_opt leftIcon,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onLeftIconClick": Js.Null_undefined.from_opt onLeftIconClick,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onRightIconClick": Js.Null_undefined.from_opt onRightIconClick,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "rightIcon": Js.Null_undefined.from_opt rightIcon,
        "scrollHide": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean scrollHide),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "title": Js.Null_undefined.from_opt title
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/autocomplete/Autocomplete"];
  let make
      allowCreate::(allowCreate: option bool)=?
      className::(className: option string)=?
      direction::(direction: option Direction.t)=?
      disabled::(disabled: option bool)=?
      error::(error: option ReasonReact.reactElement)=?
      floating::(floating: option bool)=?
      hint::(hint: option ReasonReact.reactElement)=?
      icon::(icon: option ReasonReact.reactElement)=?
      keepFocusOnChange::(keepFocusOnChange: option bool)=?
      label::(label: option ReasonReact.reactElement)=?
      maxLength::(maxLength: option float)=?
      multiline::(multiline: option bool)=?
      multiple::(multiple: option bool)=?
      name::(name: option string)=?
      onBlur::(onBlur: option (ReactEventRe.Focus.t => string => unit))=?
      onChange::(onChange: option ('value => ReactEventRe.Mouse.t => unit))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onFocus::(onFocus: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onKeyDown::(onKeyDown: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onKeyPress::(onKeyPress: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onKeyUp::(onKeyUp: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onQueryChange::(onQueryChange: option (ReasonReact.Callback.t string))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      required::(required: option bool)=?
      rows::(rows: option float)=?
      selectedPosition::(selectedPosition: option SelectedPosition.t)=?
      showSelectedWhenNotInSource::(showSelectedWhenNotInSource: option bool)=?
      showSuggestionsWhenValueIsSet::(showSuggestionsWhenValueIsSet: option bool)=?
      source::(source: option 'a)=?
      style::(style: option ReactDOMRe.style)=?
      suggestionMatch::(suggestionMatch: option SuggestionMatch.t)=?
      theme::(theme: option 'b)=?
      _type::(_type: option string)=?
      value::(value: option 'c)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "allowCreate": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean allowCreate),
        "className": Js.Null_undefined.from_opt className,
        "direction": Js.Null_undefined.from_opt (optionMap Direction.to_string direction),
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "error": Js.Null_undefined.from_opt error,
        "floating": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean floating),
        "hint": Js.Null_undefined.from_opt hint,
        "icon": Js.Null_undefined.from_opt icon,
        "keepFocusOnChange":
          Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean keepFocusOnChange),
        "label": Js.Null_undefined.from_opt label,
        "maxLength": Js.Null_undefined.from_opt maxLength,
        "multiline": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean multiline),
        "multiple": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean multiple),
        "name": Js.Null_undefined.from_opt name,
        "onBlur": Js.Null_undefined.from_opt onBlur,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onFocus": Js.Null_undefined.from_opt onFocus,
        "onKeyDown": Js.Null_undefined.from_opt onKeyDown,
        "onKeyPress": Js.Null_undefined.from_opt onKeyPress,
        "onKeyUp": Js.Null_undefined.from_opt onKeyUp,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onQueryChange": Js.Null_undefined.from_opt onQueryChange,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "required": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean required),
        "rows": Js.Null_undefined.from_opt rows,
        "selectedPosition":
          Js.Null_undefined.from_opt (optionMap SelectedPosition.to_string selectedPosition),
        "showSelectedWhenNotInSource":
          Js.Null_undefined.from_opt (
            optionMap Js.Boolean.to_js_boolean showSelectedWhenNotInSource
          ),
        "showSuggestionsWhenValueIsSet":
          Js.Null_undefined.from_opt (
            optionMap Js.Boolean.to_js_boolean showSuggestionsWhenValueIsSet
          ),
        "source": Js.Null_undefined.from_opt source,
        "style": Js.Null_undefined.from_opt style,
        "suggestionMatch":
          Js.Null_undefined.from_opt (optionMap SuggestionMatch.to_string suggestionMatch),
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt _type,
        "value": Js.Null_undefined.from_opt value
      }
      children;
};

module Avatar = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/avatar/Avatar"];
  let make
      className::(className: option string)=?
      cover::(cover: option bool)=?
      icon::(icon: option ReasonReact.reactElement)=?
      image::(image: option ReasonReact.reactElement)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      title::(title: option string)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "cover": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean cover),
        "icon": Js.Null_undefined.from_opt icon,
        "image": Js.Null_undefined.from_opt image,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "title": Js.Null_undefined.from_opt title
      }
      children;
};

module BrowseButton = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/button/BrowseButton"];
  let make
      accent::(accent: option bool)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      flat::(flat: option bool)=?
      floating::(floating: option bool)=?
      href::(href: option string)=?
      icon::(icon: option ReasonReact.reactElement)=?
      inverse::(inverse: option bool)=?
      label::(label: option string)=?
      mini::(mini: option bool)=?
      neutral::(neutral: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      primary::(primary: option bool)=?
      raised::(raised: option bool)=?
      ripple::(ripple: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      _type::(_type: option string)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "accent": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean accent),
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "flat": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean flat),
        "floating": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean floating),
        "href": Js.Null_undefined.from_opt href,
        "icon": Js.Null_undefined.from_opt icon,
        "inverse": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean inverse),
        "label": Js.Null_undefined.from_opt label,
        "mini": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean mini),
        "neutral": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean neutral),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "primary": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean primary),
        "raised": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean raised),
        "ripple": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean ripple),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt _type
      }
      children;
};

module Button = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/button/Button"];
  let make
      accent::(accent: option bool)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      flat::(flat: option bool)=?
      floating::(floating: option bool)=?
      href::(href: option string)=?
      icon::(icon: option ReasonReact.reactElement)=?
      inverse::(inverse: option bool)=?
      label::(label: option string)=?
      mini::(mini: option bool)=?
      neutral::(neutral: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      primary::(primary: option bool)=?
      raised::(raised: option bool)=?
      ripple::(ripple: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      _type::(_type: option string)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "accent": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean accent),
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "flat": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean flat),
        "floating": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean floating),
        "href": Js.Null_undefined.from_opt href,
        "icon": Js.Null_undefined.from_opt icon,
        "inverse": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean inverse),
        "label": Js.Null_undefined.from_opt label,
        "mini": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean mini),
        "neutral": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean neutral),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "primary": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean primary),
        "raised": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean raised),
        "ripple": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean ripple),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt _type
      }
      children;
};

module Card = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/card/Card"];
  let make
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      raised::(raised: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "raised": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean raised),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module CardActions = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/card/CardActions"];
  let make
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/card/CardMedia"];
  let make
      aspectRatio::(aspectRatio: option AspectRatio.t)=?
      className::(className: option string)=?
      color::(color: option string)=?
      contentOverlay::(contentOverlay: option bool)=?
      image::(image: option ReasonReact.reactElement)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "aspectRatio": Js.Null_undefined.from_opt (optionMap AspectRatio.to_string aspectRatio),
        "className": Js.Null_undefined.from_opt className,
        "color": Js.Null_undefined.from_opt color,
        "contentOverlay":
          Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean contentOverlay),
        "image": Js.Null_undefined.from_opt image,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module CardText = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/card/CardText"];
  let make
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module CardTitle = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/card/CardTitle"];
  let make
      avatar::(avatar: option ReasonReact.reactElement)=?
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      subtitle::(subtitle: option ReasonReact.reactElement)=?
      theme::(theme: option (Js.t {..}))=?
      title::(title: option ReasonReact.reactElement)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "avatar": Js.Null_undefined.from_opt avatar,
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "subtitle": Js.Null_undefined.from_opt subtitle,
        "theme": Js.Null_undefined.from_opt theme,
        "title": Js.Null_undefined.from_opt title
      }
      children;
};

module Checkbox = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/checkbox/Checkbox"];
  let make
      checked::(checked: option bool)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      label::(label: option ReasonReact.reactElement)=?
      name::(name: option string)=?
      onBlur::(onBlur: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onChange::(onChange: option (Js.boolean => ReactEventRe.Mouse.t => unit))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "checked": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean checked),
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "label": Js.Null_undefined.from_opt label,
        "name": Js.Null_undefined.from_opt name,
        "onBlur": Js.Null_undefined.from_opt onBlur,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module Chip = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/chip/Chip"];
  let make
      className::(className: option string)=?
      deletable::(deletable: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDeleteClick::(onDeleteClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "deletable": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean deletable),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDeleteClick": Js.Null_undefined.from_opt onDeleteClick,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/date_picker/DatePicker"];
  let make
      active::(active: option bool)=?
      autoOk::(autoOk: option bool)=?
      cancelLabel::(cancelLabel: option string)=?
      className::(className: option string)=?
      disabledDates::(disabledDates: option (array Js.Date.t))=?
      enabledDates::(enabledDates: option (array Js.Date.t))=?
      error::(error: option string)=?
      icon::(icon: option ReasonReact.reactElement)=?
      inputClassName::(inputClassName: option string)=?
      inputFormat::(inputFormat: option (Js.t {..}))=?
      label::(label: option string)=?
      locale::(locale: option [ | `Enum Locale.t | `Object (Js.t {..})])=?
      maxDate::(maxDate: option Js.Date.t)=?
      minDate::(minDate: option Js.Date.t)=?
      name::(name: option string)=?
      okLabel::(okLabel: option string)=?
      onChange::(onChange: option (Js.Date.t => ReactEventRe.Mouse.t => unit))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDismiss::(onDismiss: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onEscKeyDown::(onEscKeyDown: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onKeyPress::(onKeyPress: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onOverlayClick::(onOverlayClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      readonly::(readonly: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      sundayFirstDayOfWeek::(sundayFirstDayOfWeek: option bool)=?
      theme::(theme: option (Js.t {..}))=?
      value::(value: option [ | `Date Js.Date.t | `String string])=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "autoOk": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean autoOk),
        "cancelLabel": Js.Null_undefined.from_opt cancelLabel,
        "className": Js.Null_undefined.from_opt className,
        "disabledDates": Js.Null_undefined.from_opt disabledDates,
        "enabledDates": Js.Null_undefined.from_opt enabledDates,
        "error": Js.Null_undefined.from_opt error,
        "icon": Js.Null_undefined.from_opt icon,
        "inputClassName": Js.Null_undefined.from_opt inputClassName,
        "inputFormat": Js.Null_undefined.from_opt inputFormat,
        "label": Js.Null_undefined.from_opt label,
        "locale":
          Js.Null_undefined.from_opt (
            optionMap
              (
                fun
                | `Enum e => unwrapValue (`String (Locale.to_string e))
                | x => unwrapValue x
              )
              locale
          ),
        "maxDate": Js.Null_undefined.from_opt maxDate,
        "minDate": Js.Null_undefined.from_opt minDate,
        "name": Js.Null_undefined.from_opt name,
        "okLabel": Js.Null_undefined.from_opt okLabel,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDismiss": Js.Null_undefined.from_opt onDismiss,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onEscKeyDown": Js.Null_undefined.from_opt onEscKeyDown,
        "onKeyPress": Js.Null_undefined.from_opt onKeyPress,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onOverlayClick": Js.Null_undefined.from_opt onOverlayClick,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "readonly": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean readonly),
        "style": Js.Null_undefined.from_opt style,
        "sundayFirstDayOfWeek":
          Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean sundayFirstDayOfWeek),
        "theme": Js.Null_undefined.from_opt theme,
        "value": Js.Null_undefined.from_opt (optionMap unwrapValue value)
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/dialog/Dialog"];
  let make
      actions::(actions: option (array (Js.t {..})))=?
      active::(active: option bool)=?
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onEscKeyDown::(onEscKeyDown: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onOverlayClick::(onOverlayClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onOverlayMouseDown::
        (onOverlayMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onOverlayMouseMove::
        (onOverlayMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onOverlayMouseUp::(onOverlayMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      title::(title: option string)=?
      _type::(_type: option [ | `Enum Type.t | `String string])=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "actions": Js.Null_undefined.from_opt actions,
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onEscKeyDown": Js.Null_undefined.from_opt onEscKeyDown,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onOverlayClick": Js.Null_undefined.from_opt onOverlayClick,
        "onOverlayMouseDown": Js.Null_undefined.from_opt onOverlayMouseDown,
        "onOverlayMouseMove": Js.Null_undefined.from_opt onOverlayMouseMove,
        "onOverlayMouseUp": Js.Null_undefined.from_opt onOverlayMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "title": Js.Null_undefined.from_opt title,
        "type":
          Js.Null_undefined.from_opt (
            optionMap
              (
                fun
                | `Enum e => unwrapValue (`String (Type.to_string e))
                | x => unwrapValue x
              )
              _type
          )
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/drawer/Drawer"];
  let make
      active::(active: option bool)=?
      className::(className: option string)=?
      insideTree::(insideTree: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onOverlayClick::(onOverlayClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      _type::(_type: option Type.t)=?
      withOverlay::(withOverlay: option bool)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Null_undefined.from_opt className,
        "insideTree": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean insideTree),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onOverlayClick": Js.Null_undefined.from_opt onOverlayClick,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt (optionMap Type.to_string _type),
        "withOverlay": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean withOverlay)
      }
      children;
};

module Dropdown = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/dropdown/Dropdown"];
  let make
      allowBlank::(allowBlank: option bool)=?
      auto::(auto: option bool)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      error::(error: option string)=?
      label::(label: option string)=?
      name::(name: option string)=?
      onBlur::(onBlur: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onChange::(onChange: option ('value => ReactEventRe.Mouse.t => unit))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onFocus::(onFocus: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      required::(required: option bool)=?
      source::(source: array 'a)
      style::(style: option ReactDOMRe.style)=?
      template::(template: option (Js.t {..}))=?
      theme::(theme: option (Js.t {..}))=?
      value::(value: option [ | `String string | `Float float])=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "allowBlank": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean allowBlank),
        "auto": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean auto),
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "error": Js.Null_undefined.from_opt error,
        "label": Js.Null_undefined.from_opt label,
        "name": Js.Null_undefined.from_opt name,
        "onBlur": Js.Null_undefined.from_opt onBlur,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onFocus": Js.Null_undefined.from_opt onFocus,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "required": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean required),
        "source": source,
        "style": Js.Null_undefined.from_opt style,
        "template": Js.Null_undefined.from_opt template,
        "theme": Js.Null_undefined.from_opt theme,
        "value": Js.Null_undefined.from_opt (optionMap unwrapValue value)
      }
      children;
};

module FontIcon = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/font_icon/FontIcon"];
  let make
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      value::(value: option ReasonReact.reactElement)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "value": Js.Null_undefined.from_opt value
      }
      children;
};

module IconButton = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/button/IconButton"];
  let make
      accent::(accent: option bool)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      href::(href: option string)=?
      icon::(icon: option ReasonReact.reactElement)=?
      inverse::(inverse: option bool)=?
      neutral::(neutral: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      primary::(primary: option bool)=?
      ripple::(ripple: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      _type::(_type: option string)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "accent": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean accent),
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "href": Js.Null_undefined.from_opt href,
        "icon": Js.Null_undefined.from_opt icon,
        "inverse": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean inverse),
        "neutral": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean neutral),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "primary": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean primary),
        "ripple": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean ripple),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt _type
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/menu/IconMenu"];
  let make
      className::(className: option string)=?
      icon::(icon: option ReasonReact.reactElement)=?
      iconRipple::(iconRipple: option bool)=?
      menuRipple::(menuRipple: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onHide::(onHide: option (ReasonReact.Callback.t unit))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onSelect::(onSelect: option (ReasonReact.Callback.t ReactEventRe.Selection.t))=?
      onShow::(onShow: option (ReasonReact.Callback.t unit))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      position::(position: option Position.t)=?
      selectable::(selectable: option bool)=?
      selected::(selected: option 'a)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "icon": Js.Null_undefined.from_opt icon,
        "iconRipple": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean iconRipple),
        "menuRipple": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean menuRipple),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onHide": Js.Null_undefined.from_opt onHide,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onSelect": Js.Null_undefined.from_opt onSelect,
        "onShow": Js.Null_undefined.from_opt onShow,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "position": Js.Null_undefined.from_opt (optionMap Position.to_string position),
        "selectable": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "selected": Js.Null_undefined.from_opt selected,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module Input = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/input/Input"];
  let make
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      error::(error: option ReasonReact.reactElement)=?
      floating::(floating: option bool)=?
      hint::(hint: option ReasonReact.reactElement)=?
      icon::(icon: option ReasonReact.reactElement)=?
      label::(label: option ReasonReact.reactElement)=?
      maxLength::(maxLength: option float)=?
      multiline::(multiline: option bool)=?
      name::(name: option string)=?
      onBlur::(onBlur: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onChange::(onChange: option (string => ReactEventRe.Mouse.t => unit))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onFocus::(onFocus: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onKeyDown::(onKeyDown: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onKeyPress::(onKeyPress: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onKeyUp::(onKeyUp: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      required::(required: option bool)=?
      rows::(rows: option float)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      _type::(_type: option string)=?
      value::(value: option 'a)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "error": Js.Null_undefined.from_opt error,
        "floating": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean floating),
        "hint": Js.Null_undefined.from_opt hint,
        "icon": Js.Null_undefined.from_opt icon,
        "label": Js.Null_undefined.from_opt label,
        "maxLength": Js.Null_undefined.from_opt maxLength,
        "multiline": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean multiline),
        "name": Js.Null_undefined.from_opt name,
        "onBlur": Js.Null_undefined.from_opt onBlur,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onFocus": Js.Null_undefined.from_opt onFocus,
        "onKeyDown": Js.Null_undefined.from_opt onKeyDown,
        "onKeyPress": Js.Null_undefined.from_opt onKeyPress,
        "onKeyUp": Js.Null_undefined.from_opt onKeyUp,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "required": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean required),
        "rows": Js.Null_undefined.from_opt rows,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt _type,
        "value": Js.Null_undefined.from_opt value
      }
      children;
};

module Layout = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/layout/Layout"];
  let make
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module Link = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/link/Link"];
  let make
      active::(active: option bool)=?
      className::(className: option string)=?
      count::(count: option float)=?
      href::(href: option string)=?
      icon::(icon: option ReasonReact.reactElement)=?
      label::(label: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Null_undefined.from_opt className,
        "count": Js.Null_undefined.from_opt count,
        "href": Js.Null_undefined.from_opt href,
        "icon": Js.Null_undefined.from_opt icon,
        "label": Js.Null_undefined.from_opt label,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module List = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/list/List"];
  let make
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      ripple::(ripple: option bool)=?
      selectable::(selectable: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "ripple": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean ripple),
        "selectable": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module ListCheckbox = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/list/ListCheckbox"];
  let make
      caption::(caption: option string)=?
      checked::(checked: option bool)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      legend::(legend: option string)=?
      name::(name: option string)=?
      onBlur::(onBlur: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onChange::(onChange: option (ReasonReact.Callback.t ReactEventRe.Form.t))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onFocus::(onFocus: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "caption": Js.Null_undefined.from_opt caption,
        "checked": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean checked),
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "legend": Js.Null_undefined.from_opt legend,
        "name": Js.Null_undefined.from_opt name,
        "onBlur": Js.Null_undefined.from_opt onBlur,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onFocus": Js.Null_undefined.from_opt onFocus,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module ListDivider = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/list/ListDivider"];
  let make
      className::(className: option string)=?
      inset::(inset: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "inset": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean inset),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module ListItemAction = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/list/ListItemAction"];
  let make
      action::(action: option ReasonReact.reactElement)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "action": Js.Null_undefined.from_opt action,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/list/ListItemActions"];
  let make theme::(theme: option 'a)=? _type::(_type: option Type.t)=? children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt (optionMap Type.to_string _type)
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/list/ListItemContent"];
  let make
      caption::(caption: option ReasonReact.reactElement)=?
      legend::(legend: option string)=?
      theme::(theme: option (Js.t {..}))=?
      _type::(_type: option Type.t)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "caption": Js.Null_undefined.from_opt caption,
        "legend": Js.Null_undefined.from_opt legend,
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt (optionMap Type.to_string _type)
      }
      children;
};

module ListItemLayout = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/list/ListItemLayout"];
  let make
      avatar::(avatar: option [ | `String string | `Element ReasonReact.reactElement])=?
      caption::(caption: option string)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      itemContent::(itemContent: option (Js.t {..}))=?
      leftActions::(leftActions: option (array ReasonReact.reactElement))=?
      leftIcon::(leftIcon: option [ | `String string | `Element ReasonReact.reactElement])=?
      legend::(legend: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      rightActions::(rightActions: option (array ReasonReact.reactElement))=?
      rightIcon::(rightIcon: option [ | `String string | `Element ReasonReact.reactElement])=?
      selectable::(selectable: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option 'a)=?
      _to::(_to: option string)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "avatar": Js.Null_undefined.from_opt (optionMap unwrapValue avatar),
        "caption": Js.Null_undefined.from_opt caption,
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "itemContent": Js.Null_undefined.from_opt itemContent,
        "leftActions": Js.Null_undefined.from_opt leftActions,
        "leftIcon": Js.Null_undefined.from_opt (optionMap unwrapValue leftIcon),
        "legend": Js.Null_undefined.from_opt legend,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "rightActions": Js.Null_undefined.from_opt rightActions,
        "rightIcon": Js.Null_undefined.from_opt (optionMap unwrapValue rightIcon),
        "selectable": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "to": Js.Null_undefined.from_opt _to
      }
      children;
};

module ListItemText = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/list/ListItemText"];
  let make
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      primary::(primary: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "primary": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean primary),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module ListSubHeader = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/list/ListSubHeader"];
  let make
      caption::(caption: option string)=?
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "caption": Js.Null_undefined.from_opt caption,
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/menu/Menu"];
  let make
      active::(active: option bool)=?
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onHide::(onHide: option (ReasonReact.Callback.t unit))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onSelect::(onSelect: option (ReasonReact.Callback.t 'value))=?
      onShow::(onShow: option (ReasonReact.Callback.t unit))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      outline::(outline: option bool)=?
      position::(position: option Position.t)=?
      ripple::(ripple: option bool)=?
      selectable::(selectable: option bool)=?
      selected::(selected: option 'a)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onHide": Js.Null_undefined.from_opt onHide,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onSelect": Js.Null_undefined.from_opt onSelect,
        "onShow": Js.Null_undefined.from_opt onShow,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "outline": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean outline),
        "position": Js.Null_undefined.from_opt (optionMap Position.to_string position),
        "ripple": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean ripple),
        "selectable": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "selected": Js.Null_undefined.from_opt selected,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module MenuDivider = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/menu/MenuDivider"];
  let make
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module MenuItem = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/menu/MenuItem"];
  let make
      caption::(caption: string)
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      icon::(icon: option ReasonReact.reactElement)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      selected::(selected: option bool)=?
      shortcut::(shortcut: option string)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "caption": caption,
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "icon": Js.Null_undefined.from_opt icon,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "selected": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean selected),
        "shortcut": Js.Null_undefined.from_opt shortcut,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/layout/NavDrawer"];
  let make
      active::(active: option bool)=?
      className::(className: option string)=?
      clipped::(clipped: option bool)=?
      insideTree::(insideTree: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onOverlayClick::(onOverlayClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      permanentAt::(permanentAt: option PermanentAt.t)=?
      pinned::(pinned: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      _type::(_type: option Type.t)=?
      withOverlay::(withOverlay: option bool)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Null_undefined.from_opt className,
        "clipped": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean clipped),
        "insideTree": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean insideTree),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onOverlayClick": Js.Null_undefined.from_opt onOverlayClick,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "permanentAt": Js.Null_undefined.from_opt (optionMap PermanentAt.to_string permanentAt),
        "pinned": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean pinned),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt (optionMap Type.to_string _type),
        "withOverlay": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean withOverlay)
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/navigation/Navigation"];
  let make
      actions::(actions: option (array 'a))=?
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      routes::(routes: option (array 'b))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      _type::(_type: option Type.t)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "actions": Js.Null_undefined.from_opt actions,
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "routes": Js.Null_undefined.from_opt routes,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt (optionMap Type.to_string _type)
      }
      children;
};

module Overlay = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/overlay/Overlay"];
  let make
      active::(active: option bool)=?
      className::(className: option string)=?
      invisible::(invisible: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onEscKeyDown::(onEscKeyDown: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Null_undefined.from_opt className,
        "invisible": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean invisible),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onEscKeyDown": Js.Null_undefined.from_opt onEscKeyDown,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module Panel = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/layout/Panel"];
  let make
      bodyScroll::(bodyScroll: option bool)=?
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "bodyScroll": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean bodyScroll),
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module Portal = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/hoc/Portal"];
  let make
      className::(className: option string)=?
      container::(container: option 'a)=?
      lockBody::(lockBody: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "container": Js.Null_undefined.from_opt container,
        "lockBody": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean lockBody),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/progress_bar/ProgressBar"];
  let make
      buffer::(buffer: option float)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      max::(max: option float)=?
      min::(min: option float)=?
      mode::(mode: option Mode.t)=?
      multicolor::(multicolor: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      _type::(_type: option Type.t)=?
      value::(value: option float)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "buffer": Js.Null_undefined.from_opt buffer,
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "max": Js.Null_undefined.from_opt max,
        "min": Js.Null_undefined.from_opt min,
        "mode": Js.Null_undefined.from_opt (optionMap Mode.to_string mode),
        "multicolor": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean multicolor),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt (optionMap Type.to_string _type),
        "value": Js.Null_undefined.from_opt value
      }
      children;
};

module RadioButton = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/radio/RadioButton"];
  let make
      checked::(checked: option bool)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      label::(label: option ReasonReact.reactElement)=?
      name::(name: option string)=?
      onBlur::(onBlur: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onChange::(onChange: option (ReasonReact.Callback.t ReactEventRe.Form.t))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onFocus::(onFocus: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option 'a)=?
      value::(value: option 'b)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "checked": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean checked),
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "label": Js.Null_undefined.from_opt label,
        "name": Js.Null_undefined.from_opt name,
        "onBlur": Js.Null_undefined.from_opt onBlur,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onFocus": Js.Null_undefined.from_opt onFocus,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "value": Js.Null_undefined.from_opt value
      }
      children;
};

module RadioGroup = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/radio/RadioGroup"];
  let make
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      name::(name: option string)=?
      onChange::(onChange: option (ReasonReact.Callback.t string))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      value::(value: option 'a)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "name": Js.Null_undefined.from_opt name,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "value": Js.Null_undefined.from_opt value
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/layout/Sidebar"];
  let make
      active::(active: option bool)=?
      className::(className: option string)=?
      clipped::(clipped: option bool)=?
      insideTree::(insideTree: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onOverlayClick::(onOverlayClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      permanentAt::(permanentAt: option PermanentAt.t)=?
      pinned::(pinned: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      _type::(_type: option Type.t)=?
      width::(width: option float)=?
      withOverlay::(withOverlay: option bool)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Null_undefined.from_opt className,
        "clipped": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean clipped),
        "insideTree": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean insideTree),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onOverlayClick": Js.Null_undefined.from_opt onOverlayClick,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "permanentAt": Js.Null_undefined.from_opt (optionMap PermanentAt.to_string permanentAt),
        "pinned": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean pinned),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "type": Js.Null_undefined.from_opt (optionMap Type.to_string _type),
        "width": Js.Null_undefined.from_opt width,
        "withOverlay": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean withOverlay)
      }
      children;
};

module Slider = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/slider/Slider"];
  let make
      buffer::(buffer: option float)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      editable::(editable: option bool)=?
      max::(max: option float)=?
      min::(min: option float)=?
      onChange::(onChange: option (float => ReactEventRe.Focus.t => unit))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStop::(onDragStop: option (ReasonReact.Callback.t unit))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      pinned::(pinned: option bool)=?
      snaps::(snaps: option bool)=?
      step::(step: option float)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      value::(value: option float)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "buffer": Js.Null_undefined.from_opt buffer,
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "editable": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean editable),
        "max": Js.Null_undefined.from_opt max,
        "min": Js.Null_undefined.from_opt min,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDragStop": Js.Null_undefined.from_opt onDragStop,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "pinned": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean pinned),
        "snaps": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean snaps),
        "step": Js.Null_undefined.from_opt step,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "value": Js.Null_undefined.from_opt value
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/snackbar/Snackbar"];
  let make
      action::(action: option string)=?
      active::(active: option bool)=?
      className::(className: option string)=?
      label::(label: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTimeout::(onTimeout: option (ReasonReact.Callback.t unit))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      timeout::(timeout: option float)=?
      _type::(_type: option Type.t)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "action": Js.Null_undefined.from_opt action,
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Null_undefined.from_opt className,
        "label": Js.Null_undefined.from_opt label,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTimeout": Js.Null_undefined.from_opt onTimeout,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme,
        "timeout": Js.Null_undefined.from_opt timeout,
        "type": Js.Null_undefined.from_opt (optionMap Type.to_string _type)
      }
      children;
};

module Switch = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/switch/Switch"];
  let make
      checked::(checked: option bool)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      label::(label: option string)=?
      name::(name: option string)=?
      onBlur::(onBlur: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onChange::(onChange: option (Js.boolean => ReactEventRe.Mouse.t => unit))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onFocus::(onFocus: option (ReasonReact.Callback.t ReactEventRe.Focus.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "checked": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean checked),
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "label": Js.Null_undefined.from_opt label,
        "name": Js.Null_undefined.from_opt name,
        "onBlur": Js.Null_undefined.from_opt onBlur,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onFocus": Js.Null_undefined.from_opt onFocus,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module Tab = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/tabs/Tab"];
  let make
      active::(active: option bool)=?
      activeClassName::(activeClassName: option string)=?
      className::(className: option string)=?
      disabled::(disabled: option bool)=?
      hidden::(hidden: option bool)=?
      icon::(icon: option ReasonReact.reactElement)=?
      label::(label: string)
      onActive::(onActive: option (ReasonReact.Callback.t unit))=?
      onClick::(onClick: option (ReactEventRe.Mouse.t => float => unit))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "activeClassName": Js.Null_undefined.from_opt activeClassName,
        "className": Js.Null_undefined.from_opt className,
        "disabled": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "hidden": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean hidden),
        "icon": Js.Null_undefined.from_opt icon,
        "label": label,
        "onActive": Js.Null_undefined.from_opt onActive,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module TabContent = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/tabs/TabContent"];
  let make
      active::(active: option bool)=?
      className::(className: option string)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      tabIndex::(tabIndex: option float)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Null_undefined.from_opt className,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "tabIndex": Js.Null_undefined.from_opt tabIndex,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module Table = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/table/Table"];
  let make
      className::(className: option string)=?
      multiSelectable::(multiSelectable: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onRowSelect::(onRowSelect: option (ReasonReact.Callback.t (array float)))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      selectable::(selectable: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "multiSelectable":
          Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean multiSelectable),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onRowSelect": Js.Null_undefined.from_opt onRowSelect,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "selectable": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/table/TableCell"];
  let make
      className::(className: option string)=?
      column::(column: option float)=?
      numeric::(numeric: option bool)=?
      onClick::(onClick: option (ReactEventRe.Mouse.t => float => float => unit))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      row::(row: option float)=?
      sorted::(sorted: option Sorted.t)=?
      style::(style: option ReactDOMRe.style)=?
      tagName::(tagName: option TagName.t)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "column": Js.Null_undefined.from_opt column,
        "numeric": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean numeric),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "row": Js.Null_undefined.from_opt row,
        "sorted": Js.Null_undefined.from_opt (optionMap Sorted.to_string sorted),
        "style": Js.Null_undefined.from_opt style,
        "tagName": Js.Null_undefined.from_opt (optionMap TagName.to_string tagName),
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module TableHead = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/table/TableHead"];
  let make
      className::(className: option string)=?
      displaySelect::(displaySelect: option bool)=?
      multiSelectable::(multiSelectable: option bool)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onSelect::(onSelect: option (Js.boolean => ReactEventRe.Mouse.t => unit))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      selectable::(selectable: option bool)=?
      selected::(selected: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "displaySelect":
          Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean displaySelect),
        "multiSelectable":
          Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean multiSelectable),
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onSelect": Js.Null_undefined.from_opt onSelect,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "selectable": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "selected": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean selected),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
};

module TableRow = {
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/table/TableRow"];
  let make
      className::(className: option string)=?
      idx::(idx: option float)=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onSelect::(onSelect: option (float => Js.boolean => unit))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      selectable::(selectable: option bool)=?
      selected::(selected: option bool)=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "idx": Js.Null_undefined.from_opt idx,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onSelect": Js.Null_undefined.from_opt onSelect,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "selectable": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "selected": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean selected),
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/tabs/Tabs"];
  let make
      className::(className: option string)=?
      disableAnimatedBottomBorder::(disableAnimatedBottomBorder: option bool)=?
      fixed::(fixed: option bool)=?
      hideMode::(hideMode: option HideMode.t)=?
      index::(index: option float)=?
      inverse::(inverse: option bool)=?
      onChange::(onChange: option (ReasonReact.Callback.t float))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onContextMenu::(onContextMenu: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDoubleClick::(onDoubleClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrag::(onDrag: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnd::(onDragEnd: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragEnter::(onDragEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragExit::(onDragExit: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragLeave::(onDragLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragOver::(onDragOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDragStart::(onDragStart: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDrop::(onDrop: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseDown::(onMouseDown: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseEnter::(onMouseEnter: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseLeave::(onMouseLeave: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseMove::(onMouseMove: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOut::(onMouseOut: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseOver::(onMouseOver: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onMouseUp::(onMouseUp: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onTouchCancel::(onTouchCancel: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchEnd::(onTouchEnd: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchMove::(onTouchMove: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      onTouchStart::(onTouchStart: option (ReasonReact.Callback.t ReactEventRe.Touch.t))=?
      style::(style: option ReactDOMRe.style)=?
      theme::(theme: option (Js.t {..}))=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "className": Js.Null_undefined.from_opt className,
        "disableAnimatedBottomBorder":
          Js.Null_undefined.from_opt (
            optionMap Js.Boolean.to_js_boolean disableAnimatedBottomBorder
          ),
        "fixed": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean fixed),
        "hideMode": Js.Null_undefined.from_opt (optionMap HideMode.to_string hideMode),
        "index": Js.Null_undefined.from_opt index,
        "inverse": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean inverse),
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onContextMenu": Js.Null_undefined.from_opt onContextMenu,
        "onDoubleClick": Js.Null_undefined.from_opt onDoubleClick,
        "onDrag": Js.Null_undefined.from_opt onDrag,
        "onDragEnd": Js.Null_undefined.from_opt onDragEnd,
        "onDragEnter": Js.Null_undefined.from_opt onDragEnter,
        "onDragExit": Js.Null_undefined.from_opt onDragExit,
        "onDragLeave": Js.Null_undefined.from_opt onDragLeave,
        "onDragOver": Js.Null_undefined.from_opt onDragOver,
        "onDragStart": Js.Null_undefined.from_opt onDragStart,
        "onDrop": Js.Null_undefined.from_opt onDrop,
        "onMouseDown": Js.Null_undefined.from_opt onMouseDown,
        "onMouseEnter": Js.Null_undefined.from_opt onMouseEnter,
        "onMouseLeave": Js.Null_undefined.from_opt onMouseLeave,
        "onMouseMove": Js.Null_undefined.from_opt onMouseMove,
        "onMouseOut": Js.Null_undefined.from_opt onMouseOut,
        "onMouseOver": Js.Null_undefined.from_opt onMouseOver,
        "onMouseUp": Js.Null_undefined.from_opt onMouseUp,
        "onTouchCancel": Js.Null_undefined.from_opt onTouchCancel,
        "onTouchEnd": Js.Null_undefined.from_opt onTouchEnd,
        "onTouchMove": Js.Null_undefined.from_opt onTouchMove,
        "onTouchStart": Js.Null_undefined.from_opt onTouchStart,
        "style": Js.Null_undefined.from_opt style,
        "theme": Js.Null_undefined.from_opt theme
      }
      children;
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
  external reactClass : ReasonReact.reactClass =
    "default" [@@bs.module "react-toolbox/lib/time_picker/TimePicker"];
  let make
      active::(active: option bool)=?
      cancelLabel::(cancelLabel: option string)=?
      error::(error: option string)=?
      format::(format: option Format.t)=?
      icon::(icon: option ReasonReact.reactElement)=?
      inputClassName::(inputClassName: option string)=?
      label::(label: option string)=?
      okLabel::(okLabel: option string)=?
      onChange::(onChange: option (Js.Date.t => ReactEventRe.Mouse.t => unit))=?
      onClick::(onClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onDismiss::(onDismiss: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      onEscKeyDown::(onEscKeyDown: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onKeyPress::(onKeyPress: option (ReasonReact.Callback.t ReactEventRe.Keyboard.t))=?
      onOverlayClick::(onOverlayClick: option (ReasonReact.Callback.t ReactEventRe.Mouse.t))=?
      readonly::(readonly: option bool)=?
      theme::(theme: option (Js.t {..}))=?
      value::(value: option Js.Date.t)=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::{
        "active": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "cancelLabel": Js.Null_undefined.from_opt cancelLabel,
        "error": Js.Null_undefined.from_opt error,
        "format": Js.Null_undefined.from_opt (optionMap Format.to_string format),
        "icon": Js.Null_undefined.from_opt icon,
        "inputClassName": Js.Null_undefined.from_opt inputClassName,
        "label": Js.Null_undefined.from_opt label,
        "okLabel": Js.Null_undefined.from_opt okLabel,
        "onChange": Js.Null_undefined.from_opt onChange,
        "onClick": Js.Null_undefined.from_opt onClick,
        "onDismiss": Js.Null_undefined.from_opt onDismiss,
        "onEscKeyDown": Js.Null_undefined.from_opt onEscKeyDown,
        "onKeyPress": Js.Null_undefined.from_opt onKeyPress,
        "onOverlayClick": Js.Null_undefined.from_opt onOverlayClick,
        "readonly": Js.Null_undefined.from_opt (optionMap Js.Boolean.to_js_boolean readonly),
        "theme": Js.Null_undefined.from_opt theme,
        "value": Js.Null_undefined.from_opt value
      }
      children;
};
