open Types;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

let changeName = (event, dispatch, player) => {
  switch (player) {
  | Player1Hometeam =>
    dispatch(
      ChangeNamePlayer1Hometeam(ReactEvent.Form.target(event)##value),
    )
  | Player2Hometeam =>
    dispatch(
      ChangeNamePlayer2Hometeam(ReactEvent.Form.target(event)##value),
    )
  | Player1Awayteam =>
    dispatch(
      ChangeNamePlayer1Awayteam(ReactEvent.Form.target(event)##value),
    )
  | Player2Awayteam =>
    dispatch(
      ChangeNamePlayer2Awayteam(ReactEvent.Form.target(event)##value),
    )
  };
};

[@react.component]
let make = (~state: state, ~dispatch, ~player: player) => {
  <MaterialUi_Paper>
    <form>
      <label htmlFor=fullId> {str(playerStringCap ++ team)} </label>
      <input
        value=name
        name=fullId
        onChange={event => changeName(event, dispatch, player)}
      />
      <PlayerPictureInput state dispatch />
    </form>
  </MaterialUi_Paper>;
};
