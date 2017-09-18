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
        "className": Js.Nullable.from_opt className,
        "fixed": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean fixed),
        "flat": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean flat),
        "leftIcon": Js.Nullable.from_opt leftIcon,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onLeftIconClick": Js.Nullable.from_opt onLeftIconClick,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onRightIconClick": Js.Nullable.from_opt onRightIconClick,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "rightIcon": Js.Nullable.from_opt rightIcon,
        "scrollHide": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean scrollHide),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "title": Js.Nullable.from_opt title
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
        "allowCreate": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean allowCreate),
        "className": Js.Nullable.from_opt className,
        "direction": Js.Nullable.from_opt (optionMap Direction.to_string direction),
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "error": Js.Nullable.from_opt error,
        "floating": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean floating),
        "hint": Js.Nullable.from_opt hint,
        "icon": Js.Nullable.from_opt icon,
        "keepFocusOnChange":
          Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean keepFocusOnChange),
        "label": Js.Nullable.from_opt label,
        "maxLength": Js.Nullable.from_opt maxLength,
        "multiline": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean multiline),
        "multiple": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean multiple),
        "name": Js.Nullable.from_opt name,
        "onBlur": Js.Nullable.from_opt onBlur,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onFocus": Js.Nullable.from_opt onFocus,
        "onKeyDown": Js.Nullable.from_opt onKeyDown,
        "onKeyPress": Js.Nullable.from_opt onKeyPress,
        "onKeyUp": Js.Nullable.from_opt onKeyUp,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onQueryChange": Js.Nullable.from_opt onQueryChange,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "required": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean required),
        "rows": Js.Nullable.from_opt rows,
        "selectedPosition":
          Js.Nullable.from_opt (optionMap SelectedPosition.to_string selectedPosition),
        "showSelectedWhenNotInSource":
          Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean showSelectedWhenNotInSource),
        "showSuggestionsWhenValueIsSet":
          Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean showSuggestionsWhenValueIsSet),
        "source": Js.Nullable.from_opt source,
        "style": Js.Nullable.from_opt style,
        "suggestionMatch":
          Js.Nullable.from_opt (optionMap SuggestionMatch.to_string suggestionMatch),
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt _type,
        "value": Js.Nullable.from_opt value
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
        "className": Js.Nullable.from_opt className,
        "cover": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean cover),
        "icon": Js.Nullable.from_opt icon,
        "image": Js.Nullable.from_opt image,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "title": Js.Nullable.from_opt title
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
        "accent": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean accent),
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "flat": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean flat),
        "floating": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean floating),
        "href": Js.Nullable.from_opt href,
        "icon": Js.Nullable.from_opt icon,
        "inverse": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean inverse),
        "label": Js.Nullable.from_opt label,
        "mini": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean mini),
        "neutral": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean neutral),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "primary": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean primary),
        "raised": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean raised),
        "ripple": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean ripple),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt _type
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
        "accent": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean accent),
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "flat": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean flat),
        "floating": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean floating),
        "href": Js.Nullable.from_opt href,
        "icon": Js.Nullable.from_opt icon,
        "inverse": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean inverse),
        "label": Js.Nullable.from_opt label,
        "mini": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean mini),
        "neutral": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean neutral),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "primary": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean primary),
        "raised": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean raised),
        "ripple": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean ripple),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt _type
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
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "raised": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean raised),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "aspectRatio": Js.Nullable.from_opt (optionMap AspectRatio.to_string aspectRatio),
        "className": Js.Nullable.from_opt className,
        "color": Js.Nullable.from_opt color,
        "contentOverlay": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean contentOverlay),
        "image": Js.Nullable.from_opt image,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "avatar": Js.Nullable.from_opt avatar,
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "subtitle": Js.Nullable.from_opt subtitle,
        "theme": Js.Nullable.from_opt theme,
        "title": Js.Nullable.from_opt title
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
        "checked": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean checked),
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "label": Js.Nullable.from_opt label,
        "name": Js.Nullable.from_opt name,
        "onBlur": Js.Nullable.from_opt onBlur,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "deletable": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean deletable),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDeleteClick": Js.Nullable.from_opt onDeleteClick,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "autoOk": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean autoOk),
        "cancelLabel": Js.Nullable.from_opt cancelLabel,
        "className": Js.Nullable.from_opt className,
        "disabledDates": Js.Nullable.from_opt disabledDates,
        "enabledDates": Js.Nullable.from_opt enabledDates,
        "error": Js.Nullable.from_opt error,
        "icon": Js.Nullable.from_opt icon,
        "inputClassName": Js.Nullable.from_opt inputClassName,
        "inputFormat": Js.Nullable.from_opt inputFormat,
        "label": Js.Nullable.from_opt label,
        "locale":
          Js.Nullable.from_opt (
            optionMap
              (
                fun
                | `Enum e => unwrapValue (`String (Locale.to_string e))
                | x => unwrapValue x
              )
              locale
          ),
        "maxDate": Js.Nullable.from_opt maxDate,
        "minDate": Js.Nullable.from_opt minDate,
        "name": Js.Nullable.from_opt name,
        "okLabel": Js.Nullable.from_opt okLabel,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDismiss": Js.Nullable.from_opt onDismiss,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onEscKeyDown": Js.Nullable.from_opt onEscKeyDown,
        "onKeyPress": Js.Nullable.from_opt onKeyPress,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onOverlayClick": Js.Nullable.from_opt onOverlayClick,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "readonly": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean readonly),
        "style": Js.Nullable.from_opt style,
        "sundayFirstDayOfWeek":
          Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean sundayFirstDayOfWeek),
        "theme": Js.Nullable.from_opt theme,
        "value": Js.Nullable.from_opt (optionMap unwrapValue value)
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
        "actions": Js.Nullable.from_opt actions,
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onEscKeyDown": Js.Nullable.from_opt onEscKeyDown,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onOverlayClick": Js.Nullable.from_opt onOverlayClick,
        "onOverlayMouseDown": Js.Nullable.from_opt onOverlayMouseDown,
        "onOverlayMouseMove": Js.Nullable.from_opt onOverlayMouseMove,
        "onOverlayMouseUp": Js.Nullable.from_opt onOverlayMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "title": Js.Nullable.from_opt title,
        "type":
          Js.Nullable.from_opt (
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
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Nullable.from_opt className,
        "insideTree": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean insideTree),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onOverlayClick": Js.Nullable.from_opt onOverlayClick,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt (optionMap Type.to_string _type),
        "withOverlay": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean withOverlay)
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
        "allowBlank": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean allowBlank),
        "auto": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean auto),
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "error": Js.Nullable.from_opt error,
        "label": Js.Nullable.from_opt label,
        "name": Js.Nullable.from_opt name,
        "onBlur": Js.Nullable.from_opt onBlur,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onFocus": Js.Nullable.from_opt onFocus,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "required": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean required),
        "source": source,
        "style": Js.Nullable.from_opt style,
        "template": Js.Nullable.from_opt template,
        "theme": Js.Nullable.from_opt theme,
        "value": Js.Nullable.from_opt (optionMap unwrapValue value)
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
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "value": Js.Nullable.from_opt value
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
        "accent": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean accent),
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "href": Js.Nullable.from_opt href,
        "icon": Js.Nullable.from_opt icon,
        "inverse": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean inverse),
        "neutral": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean neutral),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "primary": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean primary),
        "ripple": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean ripple),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt _type
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
        "className": Js.Nullable.from_opt className,
        "icon": Js.Nullable.from_opt icon,
        "iconRipple": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean iconRipple),
        "menuRipple": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean menuRipple),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onHide": Js.Nullable.from_opt onHide,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onSelect": Js.Nullable.from_opt onSelect,
        "onShow": Js.Nullable.from_opt onShow,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "position": Js.Nullable.from_opt (optionMap Position.to_string position),
        "selectable": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "selected": Js.Nullable.from_opt selected,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "error": Js.Nullable.from_opt error,
        "floating": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean floating),
        "hint": Js.Nullable.from_opt hint,
        "icon": Js.Nullable.from_opt icon,
        "label": Js.Nullable.from_opt label,
        "maxLength": Js.Nullable.from_opt maxLength,
        "multiline": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean multiline),
        "name": Js.Nullable.from_opt name,
        "onBlur": Js.Nullable.from_opt onBlur,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onFocus": Js.Nullable.from_opt onFocus,
        "onKeyDown": Js.Nullable.from_opt onKeyDown,
        "onKeyPress": Js.Nullable.from_opt onKeyPress,
        "onKeyUp": Js.Nullable.from_opt onKeyUp,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "required": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean required),
        "rows": Js.Nullable.from_opt rows,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt _type,
        "value": Js.Nullable.from_opt value
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
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Nullable.from_opt className,
        "count": Js.Nullable.from_opt count,
        "href": Js.Nullable.from_opt href,
        "icon": Js.Nullable.from_opt icon,
        "label": Js.Nullable.from_opt label,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "ripple": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean ripple),
        "selectable": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "caption": Js.Nullable.from_opt caption,
        "checked": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean checked),
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "legend": Js.Nullable.from_opt legend,
        "name": Js.Nullable.from_opt name,
        "onBlur": Js.Nullable.from_opt onBlur,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onFocus": Js.Nullable.from_opt onFocus,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "inset": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean inset),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
      props::{"action": Js.Nullable.from_opt action, "theme": Js.Nullable.from_opt theme}
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
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt (optionMap Type.to_string _type)
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
        "caption": Js.Nullable.from_opt caption,
        "legend": Js.Nullable.from_opt legend,
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt (optionMap Type.to_string _type)
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
        "avatar": Js.Nullable.from_opt (optionMap unwrapValue avatar),
        "caption": Js.Nullable.from_opt caption,
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "itemContent": Js.Nullable.from_opt itemContent,
        "leftActions": Js.Nullable.from_opt leftActions,
        "leftIcon": Js.Nullable.from_opt (optionMap unwrapValue leftIcon),
        "legend": Js.Nullable.from_opt legend,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "rightActions": Js.Nullable.from_opt rightActions,
        "rightIcon": Js.Nullable.from_opt (optionMap unwrapValue rightIcon),
        "selectable": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "to": Js.Nullable.from_opt _to
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
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "primary": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean primary),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "caption": Js.Nullable.from_opt caption,
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onHide": Js.Nullable.from_opt onHide,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onSelect": Js.Nullable.from_opt onSelect,
        "onShow": Js.Nullable.from_opt onShow,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "outline": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean outline),
        "position": Js.Nullable.from_opt (optionMap Position.to_string position),
        "ripple": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean ripple),
        "selectable": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "selected": Js.Nullable.from_opt selected,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "icon": Js.Nullable.from_opt icon,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "selected": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean selected),
        "shortcut": Js.Nullable.from_opt shortcut,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Nullable.from_opt className,
        "clipped": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean clipped),
        "insideTree": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean insideTree),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onOverlayClick": Js.Nullable.from_opt onOverlayClick,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "permanentAt": Js.Nullable.from_opt (optionMap PermanentAt.to_string permanentAt),
        "pinned": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean pinned),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt (optionMap Type.to_string _type),
        "withOverlay": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean withOverlay)
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
        "actions": Js.Nullable.from_opt actions,
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "routes": Js.Nullable.from_opt routes,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt (optionMap Type.to_string _type)
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
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Nullable.from_opt className,
        "invisible": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean invisible),
        "onClick": Js.Nullable.from_opt onClick,
        "onEscKeyDown": Js.Nullable.from_opt onEscKeyDown,
        "theme": Js.Nullable.from_opt theme
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
        "bodyScroll": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean bodyScroll),
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "container": Js.Nullable.from_opt container,
        "lockBody": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean lockBody),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style
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
        "buffer": Js.Nullable.from_opt buffer,
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "max": Js.Nullable.from_opt max,
        "min": Js.Nullable.from_opt min,
        "mode": Js.Nullable.from_opt (optionMap Mode.to_string mode),
        "multicolor": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean multicolor),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt (optionMap Type.to_string _type),
        "value": Js.Nullable.from_opt value
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
        "checked": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean checked),
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "label": Js.Nullable.from_opt label,
        "name": Js.Nullable.from_opt name,
        "onBlur": Js.Nullable.from_opt onBlur,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onFocus": Js.Nullable.from_opt onFocus,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "value": Js.Nullable.from_opt value
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
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "name": Js.Nullable.from_opt name,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "value": Js.Nullable.from_opt value
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
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Nullable.from_opt className,
        "clipped": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean clipped),
        "insideTree": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean insideTree),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onOverlayClick": Js.Nullable.from_opt onOverlayClick,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "permanentAt": Js.Nullable.from_opt (optionMap PermanentAt.to_string permanentAt),
        "pinned": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean pinned),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "type": Js.Nullable.from_opt (optionMap Type.to_string _type),
        "width": Js.Nullable.from_opt width,
        "withOverlay": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean withOverlay)
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
        "buffer": Js.Nullable.from_opt buffer,
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "editable": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean editable),
        "max": Js.Nullable.from_opt max,
        "min": Js.Nullable.from_opt min,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDragStop": Js.Nullable.from_opt onDragStop,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "pinned": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean pinned),
        "snaps": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean snaps),
        "step": Js.Nullable.from_opt step,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "value": Js.Nullable.from_opt value
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
        "action": Js.Nullable.from_opt action,
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Nullable.from_opt className,
        "label": Js.Nullable.from_opt label,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTimeout": Js.Nullable.from_opt onTimeout,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme,
        "timeout": Js.Nullable.from_opt timeout,
        "type": Js.Nullable.from_opt (optionMap Type.to_string _type)
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
        "checked": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean checked),
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "label": Js.Nullable.from_opt label,
        "name": Js.Nullable.from_opt name,
        "onBlur": Js.Nullable.from_opt onBlur,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onFocus": Js.Nullable.from_opt onFocus,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "activeClassName": Js.Nullable.from_opt activeClassName,
        "className": Js.Nullable.from_opt className,
        "disabled": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disabled),
        "hidden": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean hidden),
        "icon": Js.Nullable.from_opt icon,
        "label": label,
        "onActive": Js.Nullable.from_opt onActive,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "className": Js.Nullable.from_opt className,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "tabIndex": Js.Nullable.from_opt tabIndex,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "multiSelectable":
          Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean multiSelectable),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onRowSelect": Js.Nullable.from_opt onRowSelect,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "selectable": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "column": Js.Nullable.from_opt column,
        "numeric": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean numeric),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "row": Js.Nullable.from_opt row,
        "sorted": Js.Nullable.from_opt (optionMap Sorted.to_string sorted),
        "style": Js.Nullable.from_opt style,
        "tagName": Js.Nullable.from_opt (optionMap TagName.to_string tagName),
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "displaySelect": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean displaySelect),
        "multiSelectable":
          Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean multiSelectable),
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onSelect": Js.Nullable.from_opt onSelect,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "selectable": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "selected": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean selected),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "idx": Js.Nullable.from_opt idx,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onSelect": Js.Nullable.from_opt onSelect,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "selectable": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean selectable),
        "selected": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean selected),
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "className": Js.Nullable.from_opt className,
        "disableAnimatedBottomBorder":
          Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean disableAnimatedBottomBorder),
        "fixed": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean fixed),
        "hideMode": Js.Nullable.from_opt (optionMap HideMode.to_string hideMode),
        "index": Js.Nullable.from_opt index,
        "inverse": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean inverse),
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onContextMenu": Js.Nullable.from_opt onContextMenu,
        "onDoubleClick": Js.Nullable.from_opt onDoubleClick,
        "onDrag": Js.Nullable.from_opt onDrag,
        "onDragEnd": Js.Nullable.from_opt onDragEnd,
        "onDragEnter": Js.Nullable.from_opt onDragEnter,
        "onDragExit": Js.Nullable.from_opt onDragExit,
        "onDragLeave": Js.Nullable.from_opt onDragLeave,
        "onDragOver": Js.Nullable.from_opt onDragOver,
        "onDragStart": Js.Nullable.from_opt onDragStart,
        "onDrop": Js.Nullable.from_opt onDrop,
        "onMouseDown": Js.Nullable.from_opt onMouseDown,
        "onMouseEnter": Js.Nullable.from_opt onMouseEnter,
        "onMouseLeave": Js.Nullable.from_opt onMouseLeave,
        "onMouseMove": Js.Nullable.from_opt onMouseMove,
        "onMouseOut": Js.Nullable.from_opt onMouseOut,
        "onMouseOver": Js.Nullable.from_opt onMouseOver,
        "onMouseUp": Js.Nullable.from_opt onMouseUp,
        "onTouchCancel": Js.Nullable.from_opt onTouchCancel,
        "onTouchEnd": Js.Nullable.from_opt onTouchEnd,
        "onTouchMove": Js.Nullable.from_opt onTouchMove,
        "onTouchStart": Js.Nullable.from_opt onTouchStart,
        "style": Js.Nullable.from_opt style,
        "theme": Js.Nullable.from_opt theme
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
        "active": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean active),
        "cancelLabel": Js.Nullable.from_opt cancelLabel,
        "error": Js.Nullable.from_opt error,
        "format": Js.Nullable.from_opt (optionMap Format.to_string format),
        "icon": Js.Nullable.from_opt icon,
        "inputClassName": Js.Nullable.from_opt inputClassName,
        "label": Js.Nullable.from_opt label,
        "okLabel": Js.Nullable.from_opt okLabel,
        "onChange": Js.Nullable.from_opt onChange,
        "onClick": Js.Nullable.from_opt onClick,
        "onDismiss": Js.Nullable.from_opt onDismiss,
        "onEscKeyDown": Js.Nullable.from_opt onEscKeyDown,
        "onKeyPress": Js.Nullable.from_opt onKeyPress,
        "onOverlayClick": Js.Nullable.from_opt onOverlayClick,
        "readonly": Js.Nullable.from_opt (optionMap Js.Boolean.to_js_boolean readonly),
        "theme": Js.Nullable.from_opt theme,
        "value": Js.Nullable.from_opt value
      }
      children;
};
