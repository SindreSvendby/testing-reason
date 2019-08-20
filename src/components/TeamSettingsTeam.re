open Types;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

let changeName = (event, dispatch, player) => {
  switch (player) {
  | Player1Hometeam =>
    dispatch(
      ChangeName(ReactEvent.Form.target(event)##value, Player1Hometeam),
    )
  | Player2Hometeam =>
    dispatch(
      ChangeName(ReactEvent.Form.target(event)##value, Player2Hometeam),
    )
  | Player1Awayteam =>
    dispatch(
      ChangeName(ReactEvent.Form.target(event)##value, Player1Awayteam),
    )
  | Player2Awayteam =>
    dispatch(
      ChangeName(ReactEvent.Form.target(event)##value, Player2Awayteam),
    )
  };
};
  

[@react.component]
let make = (~state: state, ~dispatch, ~player: players) => {
  <div>
    // <MaterialUi_Paper>
        <PlayerPictureInput state dispatch player />
    // </MaterialUi_Paper>
        
  </div> 
};
      // <input
      //   value=info.name
      //   name=info.fullId
      //   onChange={event => changeName(event, dispatch, player)} />