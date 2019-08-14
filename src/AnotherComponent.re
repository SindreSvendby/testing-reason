let str = ReasonReact.string;

[@react.component]
let make = (~state: App2.state) => {
  <p> {str("Hei " ++ string_of_int(state.scoreA))} </p>;
};
