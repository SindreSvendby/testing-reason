let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));
/* State declaration */
type state = {
  scoreH: int,
  scoreA: int,
};

let initialState: state = {scoreA: 0, scoreH: 0};

/* Action declaration */
type action =
  | AddPointsHometeam
  | AddPointsAwayteam;

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | AddPointsHometeam => {...state, scoreH: state.scoreH + 1}
        | AddPointsAwayteam => {...state, scoreA: state.scoreA + 1}
        },
      initialState,
    );

  <div>
    <div> {str_int(state.scoreH)} </div>
    <button onClick={_event => dispatch(AddPointsHometeam)}>
      {str("Add Point")}
    </button>
    <div> {str_int(state.scoreA)} </div>
    <button onClick={_event => dispatch(AddPointsAwayteam)}>
      {str("Add Point")}
    </button>
  </div>;
};
