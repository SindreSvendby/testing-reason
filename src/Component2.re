let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));
let update = action => ReasonReact.Update(action);
/* State declaration */
type state = {
  scoreH: int,
  scoreA: int,
};

/* Action declaration */
type action =
  | AddPointsHometeam
  | AddPointsAwayteam;

let component = ReasonReact.reducerComponent("Scoreboard");

let make = _children => {
  ...component,
  initialState: () => {scoreH: 0, scoreA: 0},
  reducer: (action, state) =>
    switch (action) {
    | AddPointsHometeam => update({...state, scoreH: state.scoreH + 1})
    | AddPointsAwayteam => update({...state, scoreA: state.scoreA + 1})
    },
  render: ({send, state}) => {
    <div>
      <div> {str_int(state.scoreH)} </div>
      <button onClick={_event => send(AddPointsHometeam)}>
        {str("Add Point")}
      </button>
      <div> {str_int(state.scoreA)} </div>
      <button onClick={_event => send(AddPointsAwayteam)}>
        {str("Add Point")}
      </button>
    </div>;
  },
};
