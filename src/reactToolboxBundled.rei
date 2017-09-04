module IconMenu: {
  module Position: {
    type t =
      | Auto
      | Static
      | TopLeft
      | TopRight
      | BottomLeft
      | BottomRight;
    let to_string: t => string;
  };
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    selected::Js.t {..}? =>
    selectable::bool? =>
    position::Position.t? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onShow::(ReactEventRe.Synthetic.t => unit)? =>
    onSelect::(ReactEventRe.Selection.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onHide::(ReactEventRe.Synthetic.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    menuRipple::bool? =>
    iconRipple::bool? =>
    icon::ReasonReact.reactElement? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module ListItemText: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    primary::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Overlay: {
  let make:
    theme::Js.t {..}? =>
    onEscKeyDown::(ReactEventRe.Keyboard.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    invisible::bool? =>
    className::string? =>
    active::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Snackbar: {
  module Type: {
    type t =
      | Accept
      | Cancel
      | Warning;
    let to_string: t => string;
  };
  let make:
    _type::Type.t? =>
    timeout::float? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onTimeout::(ReactEventRe.Synthetic.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    label::string? =>
    className::string? =>
    active::bool? =>
    action::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module ListItemActions: {
  module Type: {
    type t =
      | Left
      | Right;
    let to_string: t => string;
  };
  let make:
    _type::Type.t? =>
    theme::Js.t {..}? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module DatePicker: {
  module Locale: {
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
    let to_string: t => string;
  };
  let make:
    value::[ | `Date Js.Date.t | `String string]? =>
    theme::Js.t {..}? =>
    sundayFirstDayOfWeek::bool? =>
    style::ReactDOMRe.style? =>
    readonly::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onOverlayClick::(ReactEventRe.Mouse.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onKeyPress::(ReactEventRe.Keyboard.t => unit)? =>
    onEscKeyDown::(ReactEventRe.Keyboard.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onDismiss::(ReactEventRe.Synthetic.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    okLabel::string? =>
    name::string? =>
    minDate::Js.Date.t? =>
    maxDate::Js.Date.t? =>
    locale::[ | `Enum Locale.t | `Object (Js.t {..})]? =>
    label::string? =>
    inputFormat::Js.t {..}? =>
    inputClassName::string? =>
    icon::ReasonReact.reactElement? =>
    error::string? =>
    enabledDates::array Js.Date.t? =>
    disabledDates::array Js.Date.t? =>
    className::string? =>
    cancelLabel::string? =>
    autoOk::bool? =>
    active::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module TableHead: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    selected::bool? =>
    selectable::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onSelect::(ReactEventRe.Selection.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    multiSelectable::bool? =>
    displaySelect::bool? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module ListItemContent: {
  module Type: {
    type t =
      | Auto
      | Normal
      | Large;
    let to_string: t => string;
  };
  let make:
    _type::Type.t? =>
    theme::Js.t {..}? =>
    legend::string? =>
    caption::ReasonReact.reactElement? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module RadioButton: {
  let make:
    value::Js.t {..}? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onFocus::(ReactEventRe.Focus.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    onBlur::(ReactEventRe.Focus.t => unit)? =>
    name::string? =>
    label::ReasonReact.reactElement? =>
    disabled::bool? =>
    className::string? =>
    checked::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module List: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    selectable::bool? =>
    ripple::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Chip: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onDeleteClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    deletable::bool? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module BrowseButton: {
  let make:
    _type::string? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    ripple::bool? =>
    raised::bool? =>
    primary::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    neutral::bool? =>
    mini::bool? =>
    label::string? =>
    inverse::bool? =>
    icon::ReasonReact.reactElement? =>
    href::string? =>
    floating::bool? =>
    flat::bool? =>
    disabled::bool? =>
    className::string? =>
    accent::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module IconButton: {
  let make:
    _type::string? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    ripple::bool? =>
    primary::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    neutral::bool? =>
    inverse::bool? =>
    icon::ReasonReact.reactElement? =>
    href::string? =>
    disabled::bool? =>
    className::string? =>
    accent::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Navigation: {
  module Type: {
    type t =
      | Vertical
      | Horizontal;
    let to_string: t => string;
  };
  let make:
    _type::Type.t? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    routes::array (Js.t {..})? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    actions::array (Js.t {..})? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Switch: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onFocus::(ReactEventRe.Focus.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    onBlur::(ReactEventRe.Focus.t => unit)? =>
    name::string? =>
    label::string? =>
    disabled::bool? =>
    className::string? =>
    checked::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module ListSubHeader: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    caption::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Avatar: {
  let make:
    title::string? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    image::ReasonReact.reactElement? =>
    icon::ReasonReact.reactElement? =>
    cover::bool? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module ListCheckbox: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onFocus::(ReactEventRe.Focus.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    onBlur::(ReactEventRe.Focus.t => unit)? =>
    name::string? =>
    legend::string? =>
    disabled::bool? =>
    className::string? =>
    checked::bool? =>
    caption::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module MenuDivider: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module TableRow: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    selected::bool? =>
    selectable::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onSelect::(ReactEventRe.Selection.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    idx::float? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module CardTitle: {
  let make:
    title::ReasonReact.reactElement? =>
    theme::Js.t {..}? =>
    subtitle::ReasonReact.reactElement? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    avatar::ReasonReact.reactElement? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module RadioGroup: {
  let make:
    value::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    name::string? =>
    disabled::bool? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Button: {
  let make:
    _type::string? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    ripple::bool? =>
    raised::bool? =>
    primary::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    neutral::bool? =>
    mini::bool? =>
    label::string? =>
    inverse::bool? =>
    icon::ReasonReact.reactElement? =>
    href::string? =>
    floating::bool? =>
    flat::bool? =>
    disabled::bool? =>
    className::string? =>
    accent::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module CardText: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Card: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    raised::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module AppBar: {
  let make:
    title::string? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    scrollHide::bool? =>
    rightIcon::ReasonReact.reactElement? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onRightIconClick::(ReactEventRe.Mouse.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onLeftIconClick::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    leftIcon::ReasonReact.reactElement? =>
    flat::bool? =>
    fixed::bool? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Autocomplete: {
  module SuggestionMatch: {
    type t =
      | Disabled
      | Start
      | Anywhere
      | Word;
    let to_string: t => string;
  };
  module SelectedPosition: {
    type t =
      | Above
      | Below
      | None;
    let to_string: t => string;
  };
  module Direction: {
    type t =
      | Auto
      | Up
      | Down;
    let to_string: t => string;
  };
  let make:
    value::Js.t {..}? =>
    _type::string? =>
    theme::Js.t {..}? =>
    suggestionMatch::SuggestionMatch.t? =>
    style::ReactDOMRe.style? =>
    source::Js.t {..}? =>
    showSuggestionsWhenValueIsSet::bool? =>
    showSelectedWhenNotInSource::bool? =>
    selectedPosition::SelectedPosition.t? =>
    rows::float? =>
    required::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onQueryChange::(ReactEventRe.Synthetic.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onKeyUp::(ReactEventRe.Keyboard.t => unit)? =>
    onKeyPress::(ReactEventRe.Keyboard.t => unit)? =>
    onKeyDown::(ReactEventRe.Keyboard.t => unit)? =>
    onFocus::(ReactEventRe.Focus.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    onBlur::(ReactEventRe.Focus.t => unit)? =>
    name::string? =>
    multiple::bool? =>
    multiline::bool? =>
    maxLength::float? =>
    label::ReasonReact.reactElement? =>
    keepFocusOnChange::bool? =>
    icon::ReasonReact.reactElement? =>
    hint::ReasonReact.reactElement? =>
    floating::bool? =>
    error::ReasonReact.reactElement? =>
    disabled::bool? =>
    direction::Direction.t? =>
    className::string? =>
    allowCreate::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module TableCell: {
  module TagName: {
    type t =
      | Td
      | Th;
    let to_string: t => string;
  };
  module Sorted: {
    type t =
      | Asc
      | Desc;
    let to_string: t => string;
  };
  let make:
    theme::Js.t {..}? =>
    tagName::TagName.t? =>
    style::ReactDOMRe.style? =>
    sorted::Sorted.t? =>
    row::float? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    numeric::bool? =>
    column::float? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Menu: {
  module Position: {
    type t =
      | Auto
      | Static
      | TopLeft
      | TopRight
      | BottomLeft
      | BottomRight;
    let to_string: t => string;
  };
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    selected::Js.t {..}? =>
    selectable::bool? =>
    ripple::bool? =>
    position::Position.t? =>
    outline::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onShow::(ReactEventRe.Synthetic.t => unit)? =>
    onSelect::(ReactEventRe.Selection.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onHide::(ReactEventRe.Synthetic.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    active::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module CardActions: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module MenuItem: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    shortcut::string? =>
    selected::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    icon::ReasonReact.reactElement? =>
    disabled::bool? =>
    className::string? =>
    caption::string =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module ListItemLayout: {
  let make:
    _to::string? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    selectable::bool? =>
    rightIcon::[ | `String string | `Element ReasonReact.reactElement]? =>
    rightActions::array ReasonReact.reactElement? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    legend::string? =>
    leftIcon::[ | `String string | `Element ReasonReact.reactElement]? =>
    leftActions::array ReasonReact.reactElement? =>
    itemContent::Js.t {..}? =>
    disabled::bool? =>
    className::string? =>
    caption::string? =>
    avatar::[ | `String string | `Element ReasonReact.reactElement]? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Link: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    label::string? =>
    icon::ReasonReact.reactElement? =>
    href::string? =>
    count::float? =>
    className::string? =>
    active::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module ListDivider: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    inset::bool? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Portal: {
  let make:
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    lockBody::bool? =>
    container::Js.t {..}? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Tabs: {
  module HideMode: {
    type t =
      | Display
      | Unmounted;
    let to_string: t => string;
  };
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    inverse::bool? =>
    index::float? =>
    hideMode::HideMode.t? =>
    fixed::bool? =>
    disableAnimatedBottomBorder::bool? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Table: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    selectable::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onRowSelect::(ReactEventRe.Synthetic.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    multiSelectable::bool? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Panel: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    bodyScroll::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module ProgressBar: {
  module Type: {
    type t =
      | Linear
      | Circular;
    let to_string: t => string;
  };
  module Mode: {
    type t =
      | Determinate
      | Indeterminate;
    let to_string: t => string;
  };
  let make:
    value::float? =>
    _type::Type.t? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    multicolor::bool? =>
    mode::Mode.t? =>
    min::float? =>
    max::float? =>
    disabled::bool? =>
    className::string? =>
    buffer::float? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module CardMedia: {
  module AspectRatio: {
    type t =
      | Wide
      | Square;
    let to_string: t => string;
  };
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    image::ReasonReact.reactElement? =>
    contentOverlay::bool? =>
    color::string? =>
    className::string? =>
    aspectRatio::AspectRatio.t? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Checkbox: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    onBlur::(ReactEventRe.Focus.t => unit)? =>
    name::string? =>
    label::ReasonReact.reactElement? =>
    disabled::bool? =>
    className::string? =>
    checked::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Drawer: {
  module Type: {
    type t =
      | Left
      | Right;
    let to_string: t => string;
  };
  let make:
    withOverlay::bool? =>
    _type::Type.t? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onOverlayClick::(ReactEventRe.Mouse.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    insideTree::bool? =>
    className::string? =>
    active::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Tab: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onActive::(ReactEventRe.Synthetic.t => unit)? =>
    label::string =>
    icon::ReasonReact.reactElement? =>
    hidden::bool? =>
    disabled::bool? =>
    className::string? =>
    activeClassName::string? =>
    active::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Input: {
  let make:
    value::Js.t {..}? =>
    _type::string? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    rows::float? =>
    required::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onKeyUp::(ReactEventRe.Keyboard.t => unit)? =>
    onKeyPress::(ReactEventRe.Keyboard.t => unit)? =>
    onKeyDown::(ReactEventRe.Keyboard.t => unit)? =>
    onFocus::(ReactEventRe.Focus.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    onBlur::(ReactEventRe.Focus.t => unit)? =>
    name::string? =>
    multiline::bool? =>
    maxLength::float? =>
    label::ReasonReact.reactElement? =>
    icon::ReasonReact.reactElement? =>
    hint::ReasonReact.reactElement? =>
    floating::bool? =>
    error::ReasonReact.reactElement? =>
    disabled::bool? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Layout: {
  let make:
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module TimePicker: {
  module Format: {
    type t =
      | V_24hr
      | Ampm;
    let to_string: t => string;
  };
  let make:
    value::Js.Date.t? =>
    theme::Js.t {..}? =>
    readonly::bool? =>
    onOverlayClick::(ReactEventRe.Mouse.t => unit)? =>
    onKeyPress::(ReactEventRe.Keyboard.t => unit)? =>
    onEscKeyDown::(ReactEventRe.Keyboard.t => unit)? =>
    onDismiss::(ReactEventRe.Synthetic.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    okLabel::string? =>
    label::string? =>
    inputClassName::string? =>
    icon::ReasonReact.reactElement? =>
    format::Format.t? =>
    error::string? =>
    cancelLabel::string? =>
    active::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module TabContent: {
  let make:
    theme::Js.t {..}? =>
    tabIndex::float? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    active::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module FontIcon: {
  let make:
    value::ReasonReact.reactElement? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Slider: {
  let make:
    value::float? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    step::float? =>
    snaps::bool? =>
    pinned::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStop::(ReactEventRe.Synthetic.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    min::float? =>
    max::float? =>
    editable::bool? =>
    disabled::bool? =>
    className::string? =>
    buffer::float? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Dropdown: {
  let make:
    value::[ | `String string | `Float float]? =>
    theme::Js.t {..}? =>
    template::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    source::array (Js.t {..}) =>
    required::bool? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onFocus::(ReactEventRe.Focus.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    onChange::(ReactEventRe.Form.t => unit)? =>
    onBlur::(ReactEventRe.Focus.t => unit)? =>
    name::string? =>
    label::string? =>
    error::string? =>
    disabled::bool? =>
    className::string? =>
    auto::bool? =>
    allowBlank::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Dialog: {
  module Type: {
    type t =
      | Small
      | Normal
      | Large;
    let to_string: t => string;
  };
  let make:
    _type::[ | `Enum Type.t | `String string]? =>
    title::string? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onOverlayMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onOverlayMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onOverlayMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onOverlayClick::(ReactEventRe.Mouse.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onEscKeyDown::(ReactEventRe.Keyboard.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    className::string? =>
    active::bool? =>
    actions::array (Js.t {..})? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module ListItemAction: {
  let make:
    theme::Js.t {..}? =>
    action::ReasonReact.reactElement? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module NavDrawer: {
  module Type: {
    type t =
      | Left
      | Right;
    let to_string: t => string;
  };
  module PermanentAt: {
    type t =
      | Sm
      | SmTablet
      | Md
      | Lg
      | LgTablet
      | Xl
      | Xxl
      | Xxxl;
    let to_string: t => string;
  };
  let make:
    withOverlay::bool? =>
    _type::Type.t? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    pinned::bool? =>
    permanentAt::PermanentAt.t? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onOverlayClick::(ReactEventRe.Mouse.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    insideTree::bool? =>
    clipped::bool? =>
    className::string? =>
    active::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};

module Sidebar: {
  module Type: {
    type t =
      | Left
      | Right;
    let to_string: t => string;
  };
  module PermanentAt: {
    type t =
      | Sm
      | SmTablet
      | Md
      | Lg
      | LgTablet
      | Xl
      | Xxl
      | Xxxl;
    let to_string: t => string;
  };
  let make:
    withOverlay::bool? =>
    width::float? =>
    _type::Type.t? =>
    theme::Js.t {..}? =>
    style::ReactDOMRe.style? =>
    pinned::bool? =>
    permanentAt::PermanentAt.t? =>
    onTouchStart::(ReactEventRe.Touch.t => unit)? =>
    onTouchMove::(ReactEventRe.Touch.t => unit)? =>
    onTouchEnd::(ReactEventRe.Touch.t => unit)? =>
    onTouchCancel::(ReactEventRe.Touch.t => unit)? =>
    onOverlayClick::(ReactEventRe.Mouse.t => unit)? =>
    onMouseUp::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOver::(ReactEventRe.Mouse.t => unit)? =>
    onMouseOut::(ReactEventRe.Mouse.t => unit)? =>
    onMouseMove::(ReactEventRe.Mouse.t => unit)? =>
    onMouseLeave::(ReactEventRe.Mouse.t => unit)? =>
    onMouseEnter::(ReactEventRe.Mouse.t => unit)? =>
    onMouseDown::(ReactEventRe.Mouse.t => unit)? =>
    onDrop::(ReactEventRe.Mouse.t => unit)? =>
    onDragStart::(ReactEventRe.Mouse.t => unit)? =>
    onDragOver::(ReactEventRe.Mouse.t => unit)? =>
    onDragLeave::(ReactEventRe.Mouse.t => unit)? =>
    onDragExit::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnter::(ReactEventRe.Mouse.t => unit)? =>
    onDragEnd::(ReactEventRe.Mouse.t => unit)? =>
    onDrag::(ReactEventRe.Mouse.t => unit)? =>
    onDoubleClick::(ReactEventRe.Mouse.t => unit)? =>
    onContextMenu::(ReactEventRe.Mouse.t => unit)? =>
    onClick::(ReactEventRe.Mouse.t => unit)? =>
    insideTree::bool? =>
    clipped::bool? =>
    className::string? =>
    active::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps ReasonReact.actionless;
};
