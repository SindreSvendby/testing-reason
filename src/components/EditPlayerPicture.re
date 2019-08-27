open Types;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

let changePicture = (~event: ReactEvent.Form.t, ~dispatch, ~player: players) => {
  let name = ReactEvent.Form.target(event)##value;
  if (name != "") {
    dispatch(ChangeName(ReactEvent.Form.target(event)##value, player));
  };
};

let displayNone = ReactDOMRe.Style.make(~display="none", ());

[@react.component]
let make = (~state: state, ~dispatch, ~player: players) => {
  <React.Fragment>
    <MaterialUi_Button variant=`Contained component={`String("label")}>
      <input type_="file" style=displayNone />
      "Take picture"->ReasonReact.string
    </MaterialUi_Button>
    <MaterialUi_Button onClick={_event => dispatch(Edit(Jersey))}>
      "Next"->ReasonReact.string
    </MaterialUi_Button>
  </React.Fragment>;
};