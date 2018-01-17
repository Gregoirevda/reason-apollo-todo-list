
let component = ReasonReact.statelessComponent("Todo");

module Query = Apollo.Client.Query;
module TodosQuery = [%graphql {|
    query getAllTodos {
        todos {
            id
            title
            active
        }
    }
|}];

let todosQuery = TodosQuery.make(());

let make = (_children) => {
    ...component,
    render: (_) =>
    <section className="main">
        <Query query=todosQuery>
            (
                (result, parse) => {
                    switch result {
                        | Failed(error) => <div> <String text=error/> </div>
                        | Loading => <div> <String text="Loading"/> </div>
                        | Loaded(result) => {
                            let todos = parse(result)##todos;

                            <ul className="todo-list">
                                (
                                    Array.map(todo => <TodoItem todo key=todo##id/>, todos)
                                    |> ReasonReact.arrayToElement
                                )
                            </ul>
                        }
                    }
                }
                
            )
        </Query>
    </section>
};