let str = ReasonReact.string;

[@react.component]
let make = (~state) => {
  <p> {str("Hei " ++ string_of_int(state))} </p>;
};
