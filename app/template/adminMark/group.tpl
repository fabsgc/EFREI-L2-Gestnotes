<include src="include/header"/>

<table class="table">
	<thead>
		<tr>
			<th class="matricule">Id</th>
			<th>Nom</th>
		<tr>
	</thead>
	<tbody>
		<foreach loop="$courses as $data">
			<tr>
				<td>{$data['id']}</td>
				<td><a href="/admin/mark/course/{$get['id']}/{$data['id']}">{$data['name']}</a></td>
			</tr>
		</foreach>
	<tbody>
</table>

<include src="include/footer"/>